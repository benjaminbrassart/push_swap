/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:40:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 15:26:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "pserror.h"

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		psexit(NONE);
	i = 0;
	while (++i < argc)
	{
		if (!check_arg_int(argv[i]))
			psexit(NOT_INTEGER);
		if (!check_arg_overflow(argv[i]))
			psexit(INT_OVERFLOW);
	}
}
