/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_issorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:48:23 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 20:02:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "stack.h"

t_bool	stack_issorted(t_stack const *stack, int (*cmp)(int, int))
{
	t_bool			sorted;
	t_stack_elem	*e;

	sorted = true;
	e = stack->first;
	while (sorted && e && e->next)
	{
		sorted = cmp(e->value, e->next->value);
		e = e->next;
	}
	return (sorted);
}
