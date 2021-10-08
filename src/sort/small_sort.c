/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:33:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 20:04:44 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	_small_sort(t_stack *stack, int (*cmp)(int, int), int depth)
{
	if (stack_issorted(stack, cmp))
		return ;
	
}

void	small_sort(t_stack *stack, int (*cmp)(int, int))
{
	
}
