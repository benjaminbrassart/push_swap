/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_backpush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:07:13 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/06 13:33:57 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"

void	stack_backpush(t_stack *stack, t_stack_elem *elem)
{
	if (stack->size == 0)
		stack->first = elem;
	else
		stack->last->next = elem;
	elem->prev = stack->last;
	stack->last = elem;
	++stack->size;
}
