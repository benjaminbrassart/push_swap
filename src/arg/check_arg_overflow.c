/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:39:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/07 18:47:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "pserror.h"
#include <stdlib.h>

static t_bool	_check_zero(char const **arg)
{
	unsigned int	i;

	i = 0;
	while ((*arg)[i] == '0')
		++i;
	*arg += i;
	return (i != 0 && (**arg) == 0);
}

t_bool	check_arg_overflow(char const *arg)
{
	t_bool	in_bounds;
	int		as_int;
	char	*as_str;

	while (ft_isspace(*arg))
		++arg;
	if (*arg == '-' || *arg == '+')
		++arg;
	if (_check_zero(&arg))
		return (true);
	as_int = ft_atoi(arg);
	as_str = ft_itoa(as_int);
	if (as_str)
	{
		in_bounds = (ft_strcmp(arg, as_str) == 0);
		free(as_str);
		return (in_bounds);
	}
	psexit(MALLOC_FAILED);
}
