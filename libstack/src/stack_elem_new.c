/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_elem_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:06:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:02:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include <stdlib.h>

t_stack_elem	*stack_elem_new(int value)
{
	t_stack_elem	*elem;

	elem = (t_stack_elem *)malloc(sizeof (*elem));
	if (elem)
	{
		elem->value = value;
		elem->prev = NULL;
		elem->next = NULL;
	}
	return (elem);
}
