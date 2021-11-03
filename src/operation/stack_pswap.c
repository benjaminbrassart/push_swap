/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:22:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 10:52:12 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "stack_operation.h"

void	stack_pswap(t_stack *stack)
{
	stack_swap(stack);
	ft_printf("s%c\n", stack->id);
}
