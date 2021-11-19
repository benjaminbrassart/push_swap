/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 09:07:35 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_stdio.h"
#include "optimization.h"
#include "pserror.h"
#include "sort.h"
#include "stack.h"
#include "util.h"
#include <stdlib.h>

static int	free_return(void *ptr, int ret_val)
{
	free(ptr);
	return (ret_val);
}

static int	_get_index(int i, int *values, unsigned int len)
{
	unsigned int	n;

	n = 0;
	while (n < len)
	{
		if (values[n] == i)
			return ((int)n);
		++n;
	}
	return (-1);
}

static t_bool	_values_remap(int *values, unsigned int len)
{
	unsigned int	n;
	int *const		new_values = insertion_sort(values, len);

	if (!new_values)
		return (false);
	n = -1;
	while (++n < len)
		values[n] = _get_index(values[n], new_values, len);
	free(new_values);
	return (stack_fill(get_stack('a'), values, len) != 0);
}

int	main(int argc, char *argv[])
{
	int				*values;
	t_size			values_len;

	if (argc == 1)
		return (0);
	if (!check_args(argc, argv))
		return (1);
	values = parse_args(argc, argv, &values_len);
	if (!(values && check_duplicate(values, values_len)
			&& _values_remap(values, values_len)))
		free_return(values, 1);
	if (get_stack('a')->size >= 7)
		sort(get_highest_most_significant_bit(values, values_len));
	else if (!sort_small(get_median(get_stack('a'))))
		return (free_return(values, 1));
	stack_delete(get_stack('a'), FT_NULL);
	stack_delete(get_stack('b'), FT_NULL);
	return (free_return(values, 0));
}
