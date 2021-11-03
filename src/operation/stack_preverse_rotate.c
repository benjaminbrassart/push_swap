/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_preverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:21:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 10:52:07 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "stack_operation.h"

void	stack_preverse_rotate(t_stack *stack)
{
	stack_reverse_rotate(stack);
	ft_printf("r%c\n", stack->id);
}
