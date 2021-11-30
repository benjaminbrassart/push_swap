# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:57:04 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/30 06:17:40 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap

CFLAGS					= -Wall -Werror -Wextra -c -MMD $(INCLUDE)

LDFLAGS					= -L$(DIR_LIBFT) -L$(DIR_LIBSTACK) -lft -lstack

ifeq ($(DEBUG), true)
CFLAGS					+= -g

LDFLAGS					+= -g
endif

DIR_SRC					= src

SRC						= main.c \
							$(addprefix arg/, \
								check_args.c check_duplicate.c parse_args.c \
							) \
							$(addprefix error/, \
								print_error.c \
							) \
							$(addprefix operation/, \
								do_pa.c do_pb.c do_ra.c do_rb.c do_rr.c \
								do_rra.c do_rrb.c do_rrr.c do_sa.c do_sb.c \
								do_ss.c do_op.c get_op.c undo_op.c \
								invalid_operation.c g_ops.c stack_pswap.c \
								stack_protate.c stack_preverse_rotate.c \
								stack_ppush.c \
							) \
							$(addprefix sort/, \
								sort.c sort_small.c get_median.c \
							) \
							$(addprefix stack/, \
								get_stack.c opposite_stack.c stack_print.c \
							) \
							$(addprefix util/, \
								get_cmp.c swap_i.c get_most_significant_bit.c \
								get_highest_most_significant_bit.c \
								insertion_sort.c \
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
						$(MAKE) -C $(@D) DEBUG=$(DEBUG) $(@F)

all:					$(NAME)

clean:
						rm -rf $(DIR_OBJ)

fclean:					clean
						rm -f $(NAME)

re:						fclean all

.PHONY:					all clean fclean re
