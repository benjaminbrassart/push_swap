/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_foreach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:12:12 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/28 21:14:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include <stdlib.h>

void	stack_foreach(t_stack *stack, int (*f)(t_stack_elem *))
{
	t_stack_elem	*elem;
	t_stack_elem	*slow;

	if (f == NULL)
		return ;
	elem = stack->first;
	while (elem)
	{
		slow = elem->next;
		if (f(elem) == 0)
			break ;
		elem = slow;
	}
}
