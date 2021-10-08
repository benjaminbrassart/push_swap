/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:39:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 18:38:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
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
	ft_putendl_fd("Error: memory allocation failed.", 2);
	exit(1);
}
