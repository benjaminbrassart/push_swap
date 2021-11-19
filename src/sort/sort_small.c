/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:39:53 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 09:04:21 by bbrassar         ###   ########.fr       */
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

static void	_solve_pattern(t_stack *stack, unsigned int pattern)
{
	if (pattern == 312)
		stack_protate(stack);
	else if (pattern == 213)
		stack_pswap(stack);
	else if (pattern == 132)
	{
		stack_preverse_rotate(stack);
		_solve_pattern(stack, 213);
	}
	else if (pattern == 321)
	{
		stack_pswap(stack);
		_solve_pattern(stack, 231);
	}
	else if (pattern == 231)
		stack_preverse_rotate(stack);
}

static unsigned int	_get_pattern(int elems[3], t_comparator cmp)
{
	if (cmp(elems[0], elems[1]))
	{
		if (cmp(elems[1], elems[2]))
			return (123);
		if (cmp(elems[0], elems[2]))
			return (132);
		return (231);
	}
	if (cmp(elems[0], elems[2]))
		return (213);
	if (cmp(elems[1], elems[2]))
		return (312);
	return (321);
}

static void	_sort3(t_stack *stack, t_order order)
{
	int					elems[3];
	unsigned int		pattern;
	t_comparator const	cmp = get_cmp(order);

	if (_init_elems(stack, elems) < 3)
	{
		if (stack->size == 1)
			return ;
		if (cmp(elems[1], elems[0]))
			stack_pswap(stack);
		return ;
	}
	pattern = _get_pattern(elems, cmp);
	_solve_pattern(stack, pattern);
}

t_bool	sort_small(int median)
{
	t_stack *const		a = get_stack('a');
	t_stack *const		b = get_stack('b');
	unsigned int const	osz = a->size;
	unsigned int		i;

	if (median == -1)
		return (false);
	if (osz <= 3)
		_sort3(a, ASC);
	if (stack_issorted(a, get_cmp(ASC)))
		return (true);
	i = 0;
	while (i < osz && a->size > osz / 2 + (osz & 1))
	{
		if (a->first->value < median)
			do_pb();
		else
			do_ra();
		++i;
	}
	_sort3(a, ASC);
	_sort3(b, DESC);
	while (do_pa())
		;
	return (true);
}
