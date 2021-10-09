/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:51:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:05:52 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	undo_op(union u_op op, t_bool by_id)
{
	get_op(op, by_id).undo_fn();
}