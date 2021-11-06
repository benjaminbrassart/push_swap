/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:40:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/06 08:38:29 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"
#include "util.h"

t_bool	do_rra(void)
{
	t_stack *const	a = &_stacks()->a;

	if (a->size < 2)
		return (false);
	stack_preverse_rotate(a);
	return (true);
}
