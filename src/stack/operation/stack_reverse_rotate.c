/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:30:56 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/15 04:23:44 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_reverse_rotate(t_stack *stack)
{
	stack_frontpush(stack, stack_pop(stack));
}
