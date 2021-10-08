/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:53:29 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 19:07:29 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdio.h"
#include "stack.h"

void	stack_print(t_stack *stack)
{
	t_stack_elem	*e;
	t_size			i;

	e = stack->first;
	i = 0;
	ft_putchar(ft_toupper(stack->id));
	ft_putstr(": [");
	while (i < stack->size)
	{
		if (i++)
			ft_putstr(" -> ");
		ft_putnbr(e->value);
		e = e->next;
	}
	ft_putendl("]");
}
