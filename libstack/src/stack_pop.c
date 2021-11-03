/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:42:11 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:27:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include <stdlib.h>

t_stack_elem	*stack_pop(t_stack *stack)
{
	t_stack_elem	*last;

	if (stack->size == 0)
		return (NULL);
	last = stack->last;
	if (last->prev)
		last->prev->next = NULL;
	stack->last = last->prev;
	last->prev = NULL;
	--stack->size;
	return (last);
}
