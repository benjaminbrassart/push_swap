/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 14:44:07 by bbrassar         ###   ########.fr       */
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

	check_args(argc, argv);
	values = parse_args(argc, argv, &len);
	if (!values)
		psexit(MALLOC_FAILED);
	if (!check_duplicate(values, len))
		psexit(DUPLICATE_VALUES);
	stack_fill(a, values, len);
	stack_remap(a);
	stack_print(a);
	sort();
	psexit(NONE);
}
