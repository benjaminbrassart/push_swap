/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:18:07 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:28:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include <stdlib.h>

t_stack_elem	*stack_shift(t_stack *stack)
{
	t_stack_elem	*first;

	if (stack->size == 0)
		return (NULL);
	first = stack->first;
	if (first->next)
		first->next->prev = NULL;
	stack->first = first->next;
	first->next = NULL;
	--stack->size;
	return (first);
}
