/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:40:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 06:46:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_arg.h"
#include "ft_ctype.h"
#include "pserror.h"

t_bool	check_args(int argc, char *argv[])
{
	int		i;
	t_limit	limit;

	i = 0;
	while (++i < argc)
	{
		if (!check_int(argv[i]))
			print_error(ERROR_NOT_INTEGER);
		else
		{
			limit = check_int_limits(argv[i]);
			if (limit == LIMIT_INBOUND)
				continue ;
			else if (limit == LIMIT_OVERFLOW)
				print_error(ERROR_INT_OVERFLOW);
			else if (limit == LIMIT_UNDERFLOW)
				print_error(ERROR_INT_UNDERFLOW);
			else
				print_error(ERROR_MALLOC_FAILED);
		}
		return (false);
	}
	return (true);
}
