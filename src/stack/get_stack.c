/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:26:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 06:28:41 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "stack.h"
#include "util.h"

t_stack	*get_stack(int id)
{
	static t_stacks	stacks = {
	{'a', FT_NULL, FT_NULL, 0},
	{'b', FT_NULL, FT_NULL, 0}
	};

	if (id == stacks.a.id)
		return (&stacks.a);
	if (id == stacks.b.id)
		return (&stacks.b);
	return (FT_NULL);
}
