/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:03:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:04:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static t_op	get_op_id(enum e_op id)
{
	int	i;

	i = 0;
	while (i < OPERATIONS_COUNT && g_ops[i].op != id)
		++i;
	return (g_ops[i]);
}

static t_op	get_op_name(char const *name)
{
	int	i;

	i = 0;
	while (i < OPERATIONS_COUNT && ft_strcmp(g_ops[i].name, name) != 0)
		++i;
	return (g_ops[i]);
}

t_op	get_op(union u_op op, t_bool by_id)
{
	if (by_id)
		get_op_id(op.id);
	else
		get_op_name(op.name);
}
