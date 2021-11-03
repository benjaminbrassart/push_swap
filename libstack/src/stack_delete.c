/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:08:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:31:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include <stdlib.h>

static void	_default_del(t_stack_elem *elem)
{
	free(elem);
}

void	stack_delete(t_stack *stack, void (*del_fn)(t_stack_elem *))
{
	t_stack_elem	*elem;
	t_stack_elem	*slow;

	if (del_fn == NULL)
		del_fn = _default_del;
	elem = stack->first;
	while (elem)
	{
		slow = elem->next;
		del_fn(elem);
		elem = slow;
	}
}
