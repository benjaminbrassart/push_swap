/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 07:06:51 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/14 07:36:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_elem	*stack_pop(t_stack *stack)
{
	t_stack_elem *const	e = stack->last;

	if (e)
	{
		if (e->prev)
			e->prev->next = FT_NULL;
		stack->last = e->prev;
		e->prev = FT_NULL;
		(--stack->size);
	}
	return (e);
}
