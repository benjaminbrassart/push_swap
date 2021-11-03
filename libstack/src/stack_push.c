/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:31:43 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/02 01:03:51 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_function.h"
#include "stack_operation.h"

void	stack_push(t_stack *sender, t_stack *receiver)
{
	t_stack_elem *const	elem = stack_shift(sender);

	if (elem)
		stack_frontpush(receiver, elem);
}
