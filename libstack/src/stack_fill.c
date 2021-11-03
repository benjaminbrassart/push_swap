/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:00:58 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/28 23:06:41 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include <stdlib.h>

int	stack_fill(t_stack *stack, int *values, unsigned int length)
{
	unsigned int	i;
	t_stack_elem	*elem;

	i = -1;
	while (++i < length)
	{
		elem = stack_elem_new(values[i]);
		if (elem == NULL)
		{
			stack_delete(stack, NULL);
			return (0);
		}
		stack_backpush(stack, elem);
	}
	return (1);
}
