/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:44:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 18:06:02 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	stack_delete(t_stack const *stack)
{
	t_stack_elem	*e;
	t_stack_elem	*slow;

	e = stack->first;
	while (e)
	{
		slow = e->next;
		free(e);
		e = slow;
	}
}
