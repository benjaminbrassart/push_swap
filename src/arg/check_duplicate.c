/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:41:55 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/07 18:51:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include <stdlib.h>

t_bool	check_duplicate(int *values, t_size len)
{
	t_size	i;
	t_size	j;
	t_bool	unique;

	i = 0;
	unique = true;
	while (unique && i < len)
	{
		j = i;
		while (++j < len)
		{
			if (values[i] == values[j])
				unique = false;
		}
		++i;
	}
	return (unique);
}
