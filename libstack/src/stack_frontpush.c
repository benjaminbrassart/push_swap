/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_frontpush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:10:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:58:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include <stdlib.h>

void	stack_frontpush(t_stack *stack, t_stack_elem *elem)
{
	if (stack->size == 0)
		stack->last = elem;
	else
		stack->first->prev = elem;
	elem->next = stack->first;
	stack->first = elem;
	++stack->size;
}
