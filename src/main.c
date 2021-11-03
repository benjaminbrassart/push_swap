/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:59:35 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "pserror.h"
#include "sort.h"
#include "stack.h"
#include "util.h"

int	main(int argc, char *argv[])
{
	int				*values;
	t_size			len;

	check_args(argc, argv);
	values = parse_args(argc, argv, &len);
	if (!values)
		psexit(MALLOC_FAILED);
	if (!check_duplicate(values, len))
		psexit(DUPLICATE_VALUES);
	stack_fill(&_stacks()->a, values, len);
	sort(&_stacks()->a, &_stacks()->b);
	psexit(NONE);
}
