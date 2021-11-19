/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_protate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:18:55 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:10:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"
#include <unistd.h>

void	stack_protate(t_stack *stack)
{
	char const	s[3] = {'r', stack->id, '\n'};

	stack_rotate(stack);
	write(1, s, 3);
}
