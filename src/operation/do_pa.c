/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:07:08 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/25 13:40:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

t_bool	do_pa(void)
{
	t_stack *const	b = &_stacks()->b;

	if (b->size == 0)
		return (false);
	stack_push(b, &_stacks()->a);
	return (true);
}
