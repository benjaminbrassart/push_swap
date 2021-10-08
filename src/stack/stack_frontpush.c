/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_frontpush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:05:45 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 19:22:47 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_frontpush(t_stack *stack, t_stack_elem *e)
{
	t_stack_elem *const	top = stack->first;

	if (!e)
		return ;
	if (top)
		top->prev = e;
	e->next = top;
	stack->first = e;
	if (!stack->last)
		stack->last = e;
	++(stack->size);
}
