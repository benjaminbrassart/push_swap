/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:30:56 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:32:44 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_reverse_rotate(t_stack *stack)
{
	t_stack_elem *const	top = stack->first;
	t_stack_elem *const	bottom = stack->last;

	if (top && bottom && top != bottom)
	{
		stack->last = bottom->prev;
		stack->first = bottom;
		bottom->prev->next = FT_NULL;
		bottom->prev = FT_NULL;
		top->prev = FT_NULL;
		bottom->next = top;
	}	
}
