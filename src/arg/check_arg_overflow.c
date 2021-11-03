/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:39:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/02 00:10:38 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "pserror.h"
#include <stdlib.h>

t_bool	check_arg_overflow(char const *arg)
{
	int const	i = ft_atoi(arg);
	char *const	s = ft_itoa(i);
	t_bool		inbound;

	if (s)
	{
		inbound = !ft_strcmp(arg, s) || (!i && !ft_strcmp(arg, "-0"));
		free(s);
		return (inbound);
	}
	psexit(MALLOC_FAILED);
}
