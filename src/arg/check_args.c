/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:40:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/07 17:41:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_ctype.h"
#include "pserror.h"

static void	exit_overflow_underflow(char const *arg)
{
	while (ft_isspace(*arg))
		++arg;
	if (*arg == '-')
		psexit(INT_UNDERFLOW);
	psexit(INT_OVERFLOW);
}

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
			exit_overflow_underflow(argv[i]);
	}
}
