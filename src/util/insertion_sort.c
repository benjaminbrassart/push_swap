/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:58:54 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/07 18:51:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "util.h"

static int	*_values_clone(int *values, unsigned int len)
{
	int *const	new_values = ft_calloc(len, sizeof (*new_values));

	if (new_values)
		ft_memmove(new_values, values, sizeof (*new_values) * len);
	return (new_values);
}

int	*insertion_sort(int *values, unsigned int len)
{
	int *const		new_values = _values_clone(values, len);
	unsigned int	i;
	unsigned int	j;

	if (new_values)
	{
		i = len;
		while (i--)
		{
			j = len;
			while (j--)
			{
				if (new_values[j] < new_values[i])
					swap_i(new_values + j, new_values + i);
			}
		}
	}
	return (new_values);
}
