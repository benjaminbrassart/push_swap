/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:40:33 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 10:23:28 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "ft_def.h"
# include "stack_type.h"

# define OPERATIONS_COUNT 11

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
	t_bool		(*do_fn)(void);
	t_bool		(*undo_fn)(void);
}	t_op;

union u_op
{
	enum e_op	id;
	char		*name;
};

void				stack_ppush(t_stack *sender, t_stack *receiver);

void				stack_protate(t_stack *stack);

void				stack_preverse_rotate(t_stack *stack);

void				stack_pswap(t_stack *stack);

t_op				get_op(union u_op op, t_bool by_id);

t_bool				invalid_operation(void);

t_bool				do_pa(void);

t_bool				do_pb(void);

t_bool				do_sa(void);

t_bool				do_sb(void);

t_bool				do_ss(void);

t_bool				do_ra(void);

t_bool				do_rb(void);

t_bool				do_rr(void);

t_bool				do_rra(void);

t_bool				do_rrb(void);

t_bool				do_rrr(void);

t_bool				do_op(union u_op op, t_bool by_id);

t_bool				undo_op(union u_op op, t_bool by_id);

t_op const			*g_ops(void);

#endif
