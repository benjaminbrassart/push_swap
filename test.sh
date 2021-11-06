#!/bin/sh

set -e
checker=./checker

shell=$(ps -p $$ | sed 1d | xargs | cut -d ' ' -f 4)

if test "$shell" = "zsh"; then
	setopt shwordsplit
fi

make 1> /dev/null
ops="$(./push_swap $@)"
ops_count=$(echo -n "$ops" | wc -l)
"$checker" $@
checker_status=$(echo -n "$ops" | "$checker" $@ 2>&1 || true)
if test "$checker_status" = "Error"; then
	echo "\e[31mChecker threw an error\e[0m" >&2
	exit 1
fi
echo "$checker_status\e[0m"
# echo -n "$operations" | ./checker $@
