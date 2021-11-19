/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_preverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:21:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:10:13 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"
#include <unistd.h>

void	stack_preverse_rotate(t_stack *stack)
{
	char const	s[4] = {'r', 'r', stack->id, '\n'};

	stack_reverse_rotate(stack);
	write(1, s, 4);
}
