/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:40:41 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/25 13:30:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

t_bool	do_rrb(void)
{
	t_stack *const	b = &_stacks()->b;

	if (b->size < 2)
		return (false);
	stack_reverse_rotate(b);
	return (true);
}
