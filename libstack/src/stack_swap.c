/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:39:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:42:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include "stack_operation.h"

void	stack_swap(t_stack *stack)
{
	t_stack_elem	*elems[2];

	if (stack->size >= 2)
	{
		elems[0] = stack_shift(stack);
		elems[1] = stack_shift(stack);
		stack_frontpush(stack, elems[0]);
		stack_frontpush(stack, elems[1]);
	}
}
