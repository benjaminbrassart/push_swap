/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:39:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 18:36:29 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_ctype.h"
#include "ft_stdlib.h"

t_bool	check_arg_int(char const *arg)
{
	int		i;
	char	*end;

	i = ft_strtoi(arg, (char const **)&end);
	return (*end == 0 && *arg != 0 && !ft_isspace(*arg));
}
