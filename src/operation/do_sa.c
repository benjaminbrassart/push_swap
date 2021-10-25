/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:41:45 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/25 13:40:56 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

t_bool	do_sa(void)
{
	t_stack *const	a = &_stacks()->a;

	if (a->size < 2)
		return (false);
	stack_swap(a);
	return (true);
}
