/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:14:38 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 09:00:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "pserror.h"
#include "sort.h"
#include "util.h"
#include <stdlib.h>

static int	*stack_toarray(t_stack const *stack)
{
	int				*array;
	t_stack_elem	*e;
	unsigned int	i;

	if (ft_pcalloc(stack->size, sizeof (*array), (void **)&array))
	{
		e = stack->first;
		i = -1;
		while (++i < stack->size)
		{
			array[i] = e->value;
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

int	get_median(t_stack *stack)
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
	print_error(ERROR_MALLOC_FAILED);
	return (-1);
}
