/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:22:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:46:42 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"
#include <unistd.h>

void	stack_pswap(t_stack *stack)
{
	char const	s[3] = {'s', stack->id, '\n'};

	stack_swap(stack);
	write(1, s, 3);
}
