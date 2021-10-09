/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 15:27:20 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "pserror.h"
#include "sort.h"
#include "stack.h"

int	main(int argc, char *argv[])
{
	int		*values;
	t_size	len;

	check_args(argc, argv);
	values = parse_args(argc, argv, &len);
	if (values)
	{
		if (!check_duplicate(values, len))
			psexit(DUPLICATE_VALUES);
		stack_fill(values, len);
		sort(&_stacks()->a);
		stack_delete(&_stacks()->a);
	}
	else
		psexit(MALLOC_FAILED);
	return (0);
}
