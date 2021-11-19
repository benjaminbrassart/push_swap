# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 16:41:27 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/19 12:03:38 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env sh

BOLD="\033[1m"
LIGHT_RED="\033[91m"
LIGHT_GREEN="\033[92m"
LIGHT_BLUE="\033[94m"
YELLOW="\033[33m"
RED="\033[31m"
RESET="\033[0m"

abort() {
	printf -- "${RED}$@${RESET}\n"
	exit 1
}

randset() {
	for i in $(seq 1 $1); do
		printf -- "$(od -vAn -N4 -td4 < /dev/urandom | bc) "
	done
}

valgrind_get_leaks() {	
	grep -A1 'HEAP SUMMARY' "$1" | sed '1d' | tr -d ',' |
		perl -pe 's/.* in (\d+) blocks$/$1/'
}

opts=$(getopt -o lvhn -- "$@" 2> /dev/null)

eval set -- "$opts"
while true; do
	case "$1" in
	-l)
		DO_LOG="1"
		;;
	-v)
		type valgrind 2>&1 > /dev/null || abort "Valgrind not found."
		DO_VALGRIND="1"
		;;
	-n)
		type norminette 2>&1 > /dev/null || abort "Norminette not found."
		DO_NORMINETTE="1"
		;;
	-h)
		printf -- "${YELLOW}Options help:\n"
		printf -- " ${LIGHT_BLUE}-h ${YELLOW}show this help\n"
		printf -- " ${LIGHT_BLUE}-l ${YELLOW}enable logging\n"
		printf -- " ${LIGHT_BLUE}-n ${YELLOW}enable norme check, requires norminette\n"
		printf -- " ${LIGHT_BLUE}-v ${YELLOW}enable leak check, requires valgrind\n"
		exit 0
		;;
	--)
		shift
		break
		;;
	esac
	shift
done

test "$#" -eq "3" || abort "Usage: $0 [-lv] [--] <push_swap directory> <stack size> <test count>"

test -e "$1" || abort "Directory '$1' does not exist."
test -d "$1" || abort "File '$1' is not a directory."
test -x "$1" || abort "Directory '$1' is not searchable."

echo "$2" | perl -e 'exit 1 unless <> =~ m/^\d+$/' || abort "'$2' is not a valid positive integer."
echo "$3" | perl -e 'exit 1 unless <> =~ m/^\d+$/' || abort "'$3' is not a valid positive integer."

tester_dir="$(dirname $0)"
push_swap_dir="$1"
stack_size=$(echo "$2" | bc)
test_count=$(echo "$3" | bc)
push_swap="$push_swap_dir/push_swap"
checker="$push_swap_dir/checker"

make_result=$(make -C "$push_swap_dir" 2>&1 > /dev/null) || abort "$make_result"

test -e "$push_swap" || abort "File '$push_swap' does not exist."
test -f "$push_swap" || abort "File '$push_swap' is not a regular file."
test -x "$push_swap" || abort "File '$push_swap' is not executable."

test -e "$checker" || abort "File '$checker' does not exist."
test -f "$checker" || abort "File '$checker' is not a regular file."
test -x "$checker" || abort "File '$checker' is not executable."

if [ ${DO_LOG} ]; then
	logs="$tester_dir/tester.log"
	rm -f "$logs"
fi

[ ${DO_VALGRIND} ] && valgrind="valgrind --log-file=$tester_dir/valgrind.log --show-leak-kinds=all --leak-check=full"

total=0
no_err=0
for i in $(seq 1 "$test_count"); do
	args=$(randset "$stack_size")
	push_swap_result=$($valgrind "$push_swap" $args)
	if echo "$push_swap_result" | grep -qe "^$"; then
		op_count="0"
	else
		op_count=$(echo "$push_swap_result" | wc -l)
	fi
	if test "$op_count" -gt "0"; then
		checker_result=$(echo "$push_swap_result" | "$checker" $args 2>&1)
	else
		checker_result=$(echo -n "" | "$checker" $args 2>&1)
	fi
	continue="1"

	printf -- "| ${LIGHT_BLUE}%*d ${RESET}| ${LIGHT_BLUE}checker " ${#test_count} $i
	case "$checker_result" in
		Error)
			printf -- "${RED}Error!";
			continue="";;
		KO)
			printf -- "${LIGHT_RED}";;
		*)
			printf -- "${LIGHT_GREEN}";;
	esac
	if test -n "$continue"; then
		printf -- "${BOLD}${checker_result}${RESET}     ${BOLD}${YELLOW}$op_count${RESET} ${LIGHT_BLUE}operation"
		test "$op_count" -gt "1" && printf -- "s"
		if [ ${DO_VALGRIND} ]; then
			printf -- "    ${LIGHT_BLUE}valgrind "
			leaks=$(valgrind_get_leaks "$tester_dir/valgrind.log")
			if test "$leaks" -eq "0"; then
				printf -- "${LIGHT_GREEN}OK"
			else
				printf -- "${LIGHT_RED} $leaks LEAK"
				test "$leaks" -gt "1" && printf -- "S"
			fi
		fi
		total=$(echo "$total + $op_count" | bc)
		no_err=$(echo "$no_err + 1" | bc)
	fi
	printf -- "${RESET}\n"

	if [ ${DO_LOG} ]; then
		echo "Test $i" >> "$logs"
		echo "Checker: $checker_result" >> "$logs"
		[ ${DO_VALGRIND} ] && echo "Valgrind: $leaks leaks" >> "$logs"
		echo "Operations: $op_count" >> "$logs"
		echo "Result: \n$push_swap_result" >> "$logs"
		echo "Values: " >> "$logs"
		for val in $args; do
			echo -n "$val " >> "$logs"
		done
		echo "" >> "$logs"
	fi
done

if test "$no_err" -gt "0"; then
	mean=$(echo "$total / $no_err" | bc)
	printf -- "\n ${LIGHT_BLUE}Mean: ${BOLD}${YELLOW}$mean ${RESET}${LIGHT_BLUE}operation"
	test "$mean" -gt "1" && printf -- "s"
	printf -- "${RESET}\n"
fi

if [ ${DO_NORMINETTE} ]; then
	test "$no_err" -gt "0" || echo ""
	if ! norminette "$push_swap_dir" | grep -v 'OK!$'; then
		norminette_color="${LIGHT_GREEN}"
		norminette_result="OK"
	else
		norminette_color="${LIGHT_RED}"
		norminette_result="KO"
	fi
	printf " ${LIGHT_BLUE}Norminette: ${norminette_color}${BOLD}${norminette_result}${RESET}\n"
	[ ${DO_LOG} ] && echo "Norminette: $norminette_result" >> "$logs"
fi

[ ${DO_VALGRIND} ] && rm -f "$tester_dir/valgrind.log"
