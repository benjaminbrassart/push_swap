/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_issorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:34:53 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 09:34:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"

int	stack_issorted(t_stack *stack, t_comparator cmp)
{
	t_stack_elem	*elem;

	elem = stack->first;
	while (elem)
	{
		if (elem->prev && cmp(elem->prev->value, elem->value) == 0)
			return (0);
		elem = elem->next;
	}
	return (1);
}
