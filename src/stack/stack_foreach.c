/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_foreach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:00:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 16:01:57 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "stack.h"

void	stack_foreach(t_stack *stack, t_bool (*f)(t_stack *, t_stack_elem *))
{
	t_stack_elem	*e;

	e = stack->first;
	while (e && f(stack, e))
		e = e->next;
}
