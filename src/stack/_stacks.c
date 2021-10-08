/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stacks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:21:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 19:01:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "stack.h"

struct s_stacks	*_stacks(void)
{
	static struct s_stacks	stacks = {
		{'a', FT_NULL, FT_NULL, 0},
		{'b', FT_NULL, FT_NULL, 0}
	};

	return (&stacks);
}
