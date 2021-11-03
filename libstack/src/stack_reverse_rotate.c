/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:45:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:46:37 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include "stack_operation.h"

void	stack_reverse_rotate(t_stack *stack)
{
	if (stack->size >= 2)
		stack_frontpush(stack, stack_pop(stack));
}
