# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 20:50:13 by bbrassar          #+#    #+#              #
#    Updated: 2021/11/19 07:39:14 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libstack.a

CFLAGS				= -Wall -Werror -Wextra -c -MMD -Iinclude

ifeq ($(DEBUG), true)
CFLAGS				+= -g
endif

DIR_SRC				= src

SRC					= stack_delete.c stack_reverse_rotate.c stack_elem_new.c \
						stack_pop.c stack_fill.c stack_rotate.c \
						stack_foreach.c stack_backpush.c stack_frontpush.c \
						stack_issorted.c stack_shift.c stack_push.c stack_swap.c 

DIR_OBJ				= obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

DEPENDENCIES		= $(OBJ:.o=.d)

$(NAME):			$(OBJ)
					ar rs $@ $?

-include $(DEPENDENCIES)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) $< -o $@

all:				$(NAME)

clean:
					rm -rf $(DIR_OBJ)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
