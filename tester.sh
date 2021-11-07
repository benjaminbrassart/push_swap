# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 16:41:27 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/07 16:46:26 by bbrassar         ###   ########.fr        #
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
		printf -- "%s " $(od -vAn -N4 -td4 < /dev/urandom | sed 's/^ *//')
	done
}

if test "$#" -ne "3"; then
	abort "Usage: $0 <push_swap directory> <stack size> <test count>"
fi

if ! test -e "$1"; then
	abort "Directory '$1' does not exist."
fi

if ! test -d "$1"; then
	abort "File '$1' is not a directory."
fi

if ! test -x "$1"; then
	abort "Directory '$1' is not searchable."
fi

if echo "$2" | grep -vq "^[0-9][0-9]*$"; then
	abort "'$2' is not a valid positive integer."
fi

if echo "$3" | grep -vq "^[0-9][0-9]*$"; then
	abort "'$3' is not a valid positive integer."
fi

push_swap_dir="$1"
stack_size=$(echo "$2" | bc)
test_count=$(echo "$3" | bc)
push_swap="$push_swap_dir/push_swap"
checker="$push_swap_dir/checker"

if ! make_result=$(make -C "$push_swap_dir" 2>&1 > /dev/null); then
	abort "$make_result"
fi

if ! test -e "$push_swap"; then
	abort "File '$push_swap' does not exist."
fi

if ! test -f "$push_swap"; then
	abort "File '$push_swap' is not a regular file."
fi

if ! test -x "$push_swap"; then
	abort "File '$push_swap' is not executable."
fi

if ! test -e "$checker"; then
	abort "File '$checker' does not exist."
fi

if ! test -f "$checker"; then
	abort "File '$checker' is not a regular file."
fi

if ! test -x "$checker"; then
	abort "File '$checker' is not executable."
fi

# set -x
for i in $(seq 1 "$test_count"); do
	args=$(randset "$stack_size")
	push_swap_result=$("$push_swap" $args)
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
	continue=1

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
		if test "$op_count" -gt "1"; then
			printf -- "s"
		fi
	fi
	printf -- "${RESET}\n"
done
