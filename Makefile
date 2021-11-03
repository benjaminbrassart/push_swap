# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:57:04 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/03 09:31:16 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap

CFLAGS					= -Wall -Werror -Wextra -c -MMD $(INCLUDE) -g

LDFLAGS					= -L$(DIR_LIBFT) -L$(DIR_LIBSTACK) -lft -lstack -g

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
								sort.c get_median.c small_sort.c medium_sort.c large_sort.c \
							) \
							$(addprefix util/, \
								swap_i.c \
							) \
							$(addprefix stack/, \
								_stacks.c opposite_stack.c stack_print.c \
							)

DIR_OBJ					= obj

OBJ						= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

NAME_LIBFT				= libft/libft.a

DIR_LIBFT				= $(dir $(NAME_LIBFT))

NAME_LIBSTACK			= libstack/libstack.a

DIR_LIBSTACK			= $(dir $(NAME_LIBSTACK))

LOCAL_LIBS				=  $(NAME_LIBFT) $(NAME_LIBSTACK)

INCLUDE					= -Iinclude -I$(realpath $(DIR_LIBFT))/include \
							-I$(realpath $(DIR_LIBSTACK))/include

DEPENDENCIES			= $(OBJ:.o=.d)

$(NAME):				$(LOCAL_LIBS) $(OBJ)
						$(CC) $(filter %.o, $^) -o $@ $(LDFLAGS)

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:			$(DIR_SRC)/%.c
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) $< -o $@

$(LOCAL_LIBS):
						$(MAKE) -C $(@D) $(@F) clean

all:					$(NAME)

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME)

re:						fclean all

test:
						$(MAKE) -C test

.PHONY:					all clean fclean re test
