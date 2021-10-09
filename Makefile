# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:57:04 by bbrassar          #+#    #+#              #
#    Updated: 2021/10/09 16:06:09 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap

CFLAGS					= -Wall -Werror -Wextra -c -MMD $(INCLUDE)

LDFLAGS					= -L$(DIR_LIBFT) -lft

DIR_SRC					= src

SRC						= main.c \
							$(addprefix arg/, \
								check_arg_int.c check_arg_overflow.c \
								check_args.c check_duplicate.c parse_args.c \
							) \
							$(addprefix error/, \
								psexit.c \
							) \
							$(addprefix sort/, \
								sort.c small_sort.c medium_sort.c large_sort.c \
							) \
							$(addprefix stack/, \
								_stacks.c stack_delete.c stack_fill.c \
								stack_issorted.c stack_print.c \
								stack_backpush.c \
								$(addprefix element/, \
									stack_elem_delete.c stack_elem_new.c \
								) \
								$(addprefix operation/, \
								) \
							)

DIR_OBJ					= obj

OBJ						= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

ifdef debug

CFLAGS += -g

LDFLAGS += -g

endif

NAME_LIBFT				= libft/libft.a

DIR_LIBFT				= $(dir $(NAME_LIBFT))

INCLUDE					= -I$(realpath $(DIR_LIBFT))/include -Iinclude

DEPENDENCIES			= $(OBJ:.o=.d)

$(NAME):				$(NAME_LIBFT) $(OBJ)
						$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

$(NAME_LIBFT):
						$(MAKE) -C $(DIR_LIBFT) libft.a clean

all:					$(NAME)

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME)

re:						fclean all

.PHONY:					all clean fclean re
