/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_elem_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:41:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 16:42:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "stack.h"

t_stack_elem	*stack_elem_new(int value)
{
	t_stack_elem *const	elem = ft_calloc(1, sizeof (*elem));

	if (elem)
		elem->value = value;
	return (elem);
}
