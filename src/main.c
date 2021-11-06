/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/06 08:14:18 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "pserror.h"
#include "sort.h"
#include "stack.h"
#include "util.h"

int	main(int argc, char *argv[])
{
	t_stack *const	a = &_stacks()->a;
	int				*values;
	t_size			len;
	unsigned int	msb;

	check_args(argc, argv);
	values = parse_args(argc, argv, &len);
	if (!values)
		psexit(MALLOC_FAILED);
	if (!check_duplicate(values, len))
		psexit(DUPLICATE_VALUES);
	msb = get_highest_most_significant_bit(values, len);
	stack_fill(a, values, len);
	stack_remap(a);
	if (a->size < 7)
		sort_small();
	else
		sort(msb);
	psexit(NONE);
}
