/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:23:59 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 19:26:05 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_elem	*stack_shift(t_stack *stack)
{
	t_stack_elem	*e;
	t_stack_elem	*prev;
	t_stack_elem	*next;

	e = stack->last;
	if (e)
	{
		prev = e->prev;
		next = e->next;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		--(stack->size);
	}
	return (e);
}
