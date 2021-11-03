/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_protate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:18:55 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 10:52:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "stack_operation.h"

void	stack_protate(t_stack *stack)
{
	stack_rotate(stack);
	ft_printf("r%c\n", stack->id);
}
