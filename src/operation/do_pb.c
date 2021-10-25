/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:36:36 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/25 13:40:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

t_bool	do_pb(void)
{
	t_stack *const	a = &_stacks()->a;

	if (a->size == 0)
		return (false);
	stack_push(a, &_stacks()->b);
	return (true);
}
