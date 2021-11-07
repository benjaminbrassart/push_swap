/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:39:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/07 17:15:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_ctype.h"
#include "ft_stdlib.h"

t_bool	check_arg_int(char const *arg)
{
	int	i;

	i = 0;
	while (ft_isspace(*arg))
		++arg;
	if (*arg == '+' || *arg == '-')
		++arg;
	while (ft_isdigit(arg[i]))
		++i;
	return (i != 0 && arg[i] == 0);
}

// t_bool	check_arg_int(char const *arg)
// {
// 	char	*end;

// 	ft_strtoi(arg, (char const **)&end);
// 	return (*end == 0 && *arg != 0 && !ft_isspace(*arg));
// }
