/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:38:03 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/25 13:28:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

t_bool	do_ra(void)
{
	t_stack *const	a = &_stacks()->a;

	if (a->size < 2)
		return (false);
	stack_rotate(a);
	return (true);
}
