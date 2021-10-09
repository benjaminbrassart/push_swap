/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:16:14 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 16:02:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_def.h"

typedef struct s_stack_elem	t_stack_elem;

struct s_stack_elem
{
	t_stack_elem	*next;
	t_stack_elem	*prev;
	int				value;
};

typedef struct s_stack
{
	char			id;
	t_stack_elem	*first;
	t_stack_elem	*last;
	t_size			size;
}	t_stack;

struct s_stacks
{
	t_stack	a;
	t_stack	b;
};

struct s_stacks	*_stacks(void);

void			stack_elem_delete(t_stack_elem *e);

t_stack_elem	*stack_elem_new(int value);

void			stack_backpush(t_stack *stack, t_stack_elem *e);

void			stack_delete(t_stack const *stack);

void			stack_fill(int *values, t_size len);

t_bool			stack_issorted(t_stack const *stack, int (*cmp)(int, int));

void			stack_print(t_stack *stack);

void			stack_foreach(t_stack *stack,
					t_bool (*f)(t_stack *, t_stack_elem *));

#endif
