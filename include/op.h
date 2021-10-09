/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:33 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:05:22 by bbrassar         ###   ########.fr       */
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

void				undo_pa(void);

void				undo_pb(void);

void				undo_sa(void);

void				undo_sb(void);

void				undo_ss(void);

void				undo_ra(void);

void				undo_rb(void);

void				undo_rr(void);

void				undo_rra(void);

void				undo_rrb(void);

void				undo_rrr(void);

void				undo_op(union u_op op, t_bool by_id);

static const t_op	g_ops[12] = {
	{PA, "pa", do_pa, undo_pa},
	{PB, "pb", do_pb, undo_pb},
	{SA, "sa", do_sa, undo_sa},
	{SB, "sb", do_sb, undo_sb},
	{SS, "ss", do_ss, undo_ss},
	{RA, "ra", do_ra, undo_ra},
	{RB, "rb", do_rb, undo_rb},
	{RR, "rr", do_rr, undo_rr},
	{RRA, "rra", do_rra, undo_rra},
	{RRB, "rrb", do_rrb, undo_rrb},
	{RRR, "rrr", do_rrr, undo_rrr},
	{INVALID, FT_NULL, invalid_operation, invalid_operation},
};

# define OPERATIONS_COUNT 11

#endif
