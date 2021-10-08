/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 19:30:14 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_stdio.h"
#include "sort.h"
#include "stack.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int		*values;
	t_size	len;

	check_args(argc, argv);
	values = parse_args(argc, argv, &len);
	if (values)
	{
		if (!check_duplicate(values, len))
		{
			ft_putendl_fd("Error: there are duplicate arguments.", 2);
			exit(1);
		}
		stack_fill(values, len);
		sort(&_stacks()->a);
		stack_delete(&_stacks()->a);
	}
	else
	{
		ft_putendl_fd("Error: memory allocation failed.", 2);
		exit(1);
	}
	return (0);
}
