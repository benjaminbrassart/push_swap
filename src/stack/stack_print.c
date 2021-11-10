/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:53:29 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/10 11:41:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdio.h"
#include "stack_type.h"
#include "util.h"

void	stack_print(t_stack *stack)
{
	t_stack_elem	*e;

	e = stack->first;
	ft_putc(ft_toupper(stack->id));
	ft_puts(": [");
	while (e)
	{
		if (e->prev)
			ft_puts(" -> ");
		ft_puti(e->value);
		e = e->next;
	}
	ft_putnl("]");
}
