/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:39:53 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/06 08:49:37 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"
#include "op.h"
#include "sort.h"
#include "util.h"

static unsigned int	_init_elems(t_stack *stack, int elems[3])
{
	unsigned int	i;
	t_stack_elem	*e;

	i = 0;
	e = stack->first;
	while (e && i++ < 3)
	{
		elems[i - 1] = e->value;
		e = e->next;
	}
	return (i);
}

static void	_sort3(t_stack *stack, t_order order)
{
	t_comparator const	cmp = get_cmp(order);
	int					elems[3];

	if (_init_elems(stack, elems) < 3)
	{
		if (cmp(elems[1], elems[0]))
			stack_pswap(stack);
		return ;
	}
	if (cmp(elems[0], elems[1]) && cmp(elems[1], elems[2]))
		return ;
	if ((cmp(elems[2], elems[1]) && cmp(elems[1], elems[0]))
		|| (cmp(elems[1], elems[0]) && cmp(elems[1], elems[2]))
		|| (cmp(elems[0], elems[1]) && cmp(elems[2], elems[1])))
		stack_pswap(stack);
	stack_print(stack);
	_init_elems(stack, elems);
	if (cmp(elems[1], elems[0]) && cmp(elems[1], elems[2]))
		stack_preverse_rotate(stack);
	_init_elems(stack, elems);
	if (cmp(elems[0], elems[1]) && cmp(elems[2], elems[1]))
		stack_protate(stack);
}

void	sort_small(void)
{
	t_stack *const		a = &_stacks()->a;
	t_stack *const		b = &_stacks()->b;
	int const			median = get_median(a);
	unsigned int const	osz = a->size;
	unsigned int		i;

	if (osz <= 3)
		_sort3(a, ASC);
	if (stack_issorted(a, get_cmp(ASC)))
		return ;
	stack_print(a);
	ft_printf("median: %d, original size: %u\n", median, osz);
	i = -1;
	while (++i < osz)
	{
		if (a->first->value > median)
			do_pb();
		else
			do_ra();
	}
	_sort3(a, DESC);
	_sort3(b, ASC);
	while (do_pa())
		;
}
