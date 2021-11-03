/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stacks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:21:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/28 22:57:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "util.h"

t_stacks	*_stacks(void)
{
	static t_stacks	stacks = {
		{'a', FT_NULL, FT_NULL, 0},
		{'b', FT_NULL, FT_NULL, 0}
	};

	return (&stacks);
}
