/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:33 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:45:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "ft_def.h"

enum e_op
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	INVALID,
};

typedef struct s_op
{
	enum e_op	op;
	char const	*name;
	void		(*do_fn)(void);
	void		(*undo_fn)(void);
}	t_op;

union u_op
{
	enum e_op	id;
	char const	*name;
};

t_op				get_op(union u_op op, t_bool by_id);

void				invalid_operation(void);

void				do_pa(void);

void				do_pb(void);

void				do_sa(void);

void				do_sb(void);

void				do_ss(void);

void				do_ra(void);

void				do_rb(void);

void				do_rr(void);

void				do_rra(void);

void				do_rrb(void);

void				do_rrr(void);

void				do_op(union u_op op, t_bool by_id);

void				undo_op(union u_op op, t_bool by_id);

static const t_op	g_ops[12] = {
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

# define OPERATIONS_COUNT 11

#endif
