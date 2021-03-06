/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:51:29 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/25 13:21:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_bool	do_op(union u_op op, t_bool by_id)
{
	return (get_op(op, by_id).do_fn());
}
