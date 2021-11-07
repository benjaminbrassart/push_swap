/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/07 18:51:16 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_stdio.h"
#include "pserror.h"
#include "sort.h"
#include "stack.h"
#include "util.h"
#include <stdlib.h>

static int	_get_position(int i, int *values, unsigned int len)
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

static void	_exit_free_values(int *values, t_errno error)
{
	free(values);
	psexit(error);
}

static void	_values_remap(int *values, unsigned int len)
{
	unsigned int	n;
	int *const		new_values = insertion_sort(values, len);

	if (!new_values)
		_exit_free_values(values, MALLOC_FAILED);
	n = -1;
	while (++n < len)
		values[n] = _get_position(values[n], new_values, len);
	free(new_values);
	if (!stack_fill(&_stacks()->a, values, len))
		_exit_free_values(values, MALLOC_FAILED);
}

int	main(int argc, char *argv[])
{
	int				*values;
	t_size			len;

	check_args(argc, argv);
	values = parse_args(argc, argv, &len);
	if (!check_duplicate(values, len))
		_exit_free_values(values, DUPLICATE_VALUES);
	_values_remap(values, len);
	free(values);
	if (_stacks()->a.size < 7)
		sort_small();
	else
		sort(get_highest_most_significant_bit(values, len));
	psexit(NONE);
}
