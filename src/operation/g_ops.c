/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 06:27:57 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/10 11:36:55 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op const	*g_ops(void)
{
	static const t_op	ops[OPERATIONS_COUNT + 1] = {
	{PA, "pa", do_pa, do_pb},
	{PB, "pb", do_pb, do_pa},
	{SA, "sa", do_sa, do_sa},
	{SB, "sb", do_sb, do_sb},
	{SS, "ss", do_ss, do_ss},
	{RA, "ra", do_ra, do_rra},
	{RB, "rb", do_rb, do_rrb},
	{RR, "rr", do_rr, do_rrr},
	{RRA, "rra", do_rra, do_ra},
	{RRB, "rrb", do_rrb, do_rb},
	{RRR, "rrr", do_rrr, do_rr},
	{INVALID, FT_NULL, invalid_operation, invalid_operation},
	};

	return (ops);
}
