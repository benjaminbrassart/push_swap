/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:41:55 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 17:45:12 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"

t_bool	check_duplicate(int *values, t_size len)
{
	t_size	i;
	t_size	j;

	i = 0;
	while (i < len)
	{
		j = i;
		while (++j < len)
		{
			if (values[i] == values[j])
				return (false);
		}
		++i;
	}
	return (true);
}
