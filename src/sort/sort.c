/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:28:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/06 13:22:35 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "sort.h"
#include "stack.h"
#include "util.h"
#include "ft_stdio.h"

static int	_cmp_asc(int a, int b)
{
	return (a < b);
}

void	sort(unsigned int msb)
{
	t_stack *const	a = &_stacks()->a;
	unsigned int	i;
	unsigned int	n;

	n = 0;
	while (n < msb && !stack_issorted(a, _cmp_asc))
	{
		i = a->size;
		while (i--)
		{
			if ((a->first->value & (1 << n)) == 0)
				do_pb();
			else
				do_ra();
		}
		while (do_pa())
			;
		++n;
	}
}
