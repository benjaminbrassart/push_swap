# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:57:04 by bbrassar          #+#    #+#              #
#    Updated: 2021/10/28 17:48:46 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap

CFLAGS					= -Wall -Werror -Wextra -c -MMD $(INCLUDE) -g

LDFLAGS					= -L$(DIR_LIBFT) -lft -g

DIR_SRC					= src

SRC						= main.c \
							$(addprefix arg/, \
								check_arg_int.c check_arg_overflow.c \
								check_args.c check_duplicate.c parse_args.c \
							) \
							$(addprefix error/, \
								psexit.c g_errno.c \
							) \
							$(addprefix operation/, \
								do_pa.c do_pb.c do_ra.c do_rb.c do_rr.c \
								do_rra.c do_rrb.c do_rrr.c do_sa.c do_sb.c \
								do_ss.c do_op.c get_op.c undo_op.c \
								invalid_operation.c g_ops.c \
							) \
							$(addprefix sort/, \
								sort.c get_median.c sort_small.c \
							) \
							$(addprefix stack/, \
								_stacks.c stack_delete.c stack_fill.c \
								stack_issorted.c stack_print.c stack_shift.c \
								stack_backpush.c stack_frontpush.c stack_pop.c \
								opposite_stack.c \
								$(addprefix element/, \
									stack_elem_delete.c stack_elem_new.c \
								) \
								$(addprefix operation/, \
									stack_push.c stack_swap.c stack_rotate.c \
									stack_reverse_rotate.c \
								) \
							) \
							$(addprefix util/, swap_i.c)

DIR_OBJ					= obj

OBJ						= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

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
