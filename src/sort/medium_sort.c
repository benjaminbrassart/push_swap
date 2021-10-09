/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:10:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:27:19 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "pserror.h"
#include "sort.h"
#include "util.h"
#include <stdlib.h>

static int	*stack_toarray(t_stack *stack)
{
	int				*array;
	t_stack_elem	*e;
	int				i;

	array = ft_calloc(stack->size, sizeof (*array));
	if (array)
	{
		e = stack->first;
		i = 0;
		while (e)
		{
			array[i++] = e->value;
			e = e->next;
		}
	}
	return (array);
}

static void	sort_array(int *array, t_size len)
{
	t_size	i;
	int		j;

	i = 0;
	while (++i < len)
	{
		j = (int)i - 1;
		while (j >= 0)
		{
			if (array[j] > array[j + 1])
				swap_i(array + j, array + j + 1);
			--j;
		}
	}
}

static int	get_median(t_stack *stack)
{
	int *const	array = stack_toarray(stack);
	int			median;

	if (array)
	{
		sort_array(array, stack->size);
		median = array[stack->size / 2];
		free(array);
		return (median);
	}
	psexit(MALLOC_FAILED);
}

/*
find median
push element of a < median in b
small_sort a, asc
small_sort b, desc
push element of b in a
*/
void	medium_sort(t_stack *stack)
{
	int const	median = get_median(stack);

	(void)median;
}
