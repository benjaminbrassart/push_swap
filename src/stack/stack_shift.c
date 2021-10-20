/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:23:59 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/14 07:28:13 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_elem	*stack_shift(t_stack *stack)
{
	t_stack_elem *const	e = stack->first;

	if (e)
	{
		stack->first = e->next;
		if (stack->first)
			stack->first->prev = FT_NULL;
		e->next = FT_NULL;
		--(stack->size);
	}
	return (e);
}
