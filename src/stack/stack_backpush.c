/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_backpush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:41:43 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 18:51:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_backpush(t_stack *stack, t_stack_elem *e)
{
	t_stack_elem *const	bottom = stack->last;

	if (!e)
		return ;
	if (bottom)
		bottom->next = e;
	e->prev = bottom;
	stack->last = e;
	if (!stack->first)
		stack->first = e;
	++(stack->size);
}
