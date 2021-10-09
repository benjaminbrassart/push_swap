/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:36:36 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:37:02 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

void	do_pb(void)
{
	t_stack const	*a = &_stacks()->a;
	t_stack const	*b = &_stacks()->b;

	stack_push(a, b);
}