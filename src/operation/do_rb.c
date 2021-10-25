/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:39:02 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/25 13:29:03 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

t_bool	do_rb(void)
{
	t_stack *const	b = &_stacks()->b;

	if (b->size < 2)
		return (false);
	stack_rotate(b);
	return (true);
}
