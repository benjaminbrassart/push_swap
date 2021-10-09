/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:17:58 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:33:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "util.h"

void	stack_swap(t_stack *stack)
{
	if (stack->first && stack->first->next)
		swap_i(&stack->first->value, &stack->first->next->value);
}
