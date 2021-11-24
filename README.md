# push_swap

## Quick description

This project is a program that takes signed integers as arguments and sorts them only using a set of restricted operations (see [operations](#operations))

## Installation

### Clone the repository

```sh
git clone https://github.com/benjaminbrassart/push_swap.git
```

### Compile

```sh
make
```

## How it works

This program is (mostly) based on the [radix sort algorithm](https://en.wikipedia.org/wiki/Radix_sort). It checks every bit of every value and pushes to `B` value with a bit that equals `0`. Then it pushes everything back to `A`.

## How to use

### Arguments rules
- Passing no argument *is* valid
- Prepending whitespaces are ignored (see [isspace(3)](https://man.openbsd.org/isspace.3))
- Every argument argument may have one sign (`'+'` or `'-'`) prepending the digits
- Every argument must end with decimal digits (see [isdigit(3)](https://man.openbsd.org/isdigit.3))
- A sign alone is not an integer
- An empty string is not an integer
- Values are what arguments numerically represent
- No duplicate values
- Every value must be between [`INT_MAX` and `INT_MIN`](https://pubs.opengroup.org/onlinepubs/009696899/basedefs/limits.h.html)

### Operations

| Operation | Description |
| - | - |
| `pa` | Push the top element of B at the top of A |
| `pb` | Push the top element of A at the top of B |
| `ra` | Shift up all the elements of A, and the first element becomes the last |
| `rb` | Shift up all the elements of B, and the first element becomes the last |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Shift down all the elements of A, and the last element becomes the first |
| `rrb` | Shift down all the elements of B, and the last element becomes the first |
| `rrr` | `rra` and `rrb`  at the same time |
| `sa` | Swap the first two elements of A |
| `sb` | Swap the first two elements of B |
| `ss` | `sa` and `sb`  at the same time |

### Testing with a checker

```sh
# zsh does not expand variables like other shells such as bash.
# more precisely, it does *not* split arguments by default when invoking commands, resulting, in the following case, in one big string passed as argument.
# in order to have the expected behavior, zsh users must enable the shwordsplit option:
setopt shwordsplit

ARGS="1 2 3"
./push_swap $ARGS | ./checker $ARGS
```

## Test script

### Basic usage

A test script comes with the repository. You may launch it like this:

```sh
# ./tester.sh <push_swap directory> <stack size> <test count>
./tester ~/push_swap 100 42 # start 42 tests on stacks of 100 random elements
```
### Options

| Option | Description |
| - | - |
| -h | Display options help |
| -n | Check norme using `norminette` |
| -v | Check memory leaks using `valgrind` |
| -l | Enable logging in `tester.log` |
