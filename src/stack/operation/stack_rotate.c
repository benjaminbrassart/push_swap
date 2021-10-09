/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:28:51 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:30:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_rotate(t_stack *stack)
{
	t_stack_elem *const	top = stack->first;
	t_stack_elem *const	bottom = stack->last;

	if (top && bottom && top != bottom)
	{
		stack->first = top->next;
		stack->last = top;
		top->next->prev = FT_NULL;
		top->next = FT_NULL;
		top->prev = bottom;
		bottom->next = top;
	}
}
