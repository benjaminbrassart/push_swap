/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:07:08 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:12:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"
#include "util.h"

t_bool	do_pa(void)
{
	t_stack *const	b = get_stack('b');

	if (b->size == 0)
		return (false);
	stack_ppush(b, get_stack('a'));
	return (true);
}
