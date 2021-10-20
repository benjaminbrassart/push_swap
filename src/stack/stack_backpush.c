/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_backpush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:41:43 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/15 04:21:29 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_backpush(t_stack *stack, t_stack_elem *e)
{
	t_stack_elem *const	bottom = stack->last;

	if (!e)
		return ;
	e->prev = bottom;
	stack->last = e;
	if (bottom)
		bottom->next = e;
	if (!stack->first)
		stack->first = e;
	++(stack->size);
}
