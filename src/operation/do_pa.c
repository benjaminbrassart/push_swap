/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:07:08 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 17:36:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "stack.h"

void	do_pa(void)
{
	t_stack const	*a = &_stacks()->a;
	t_stack const	*b = &_stacks()->b;

	stack_push(b, a);
}
