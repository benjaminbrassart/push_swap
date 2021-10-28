/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opposite_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:45:28 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/28 17:48:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*opposite_stack(t_stack *stack)
{
	struct s_stacks *const	stacks = _stacks();

	if (stack == &stacks->a)
		return (&stacks->b);
	return (&stacks->a);
}
