/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:28:46 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 20:09:04 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

static int	_compare_asc(int a, int b)
{
	return (a < b);
}

void	sort(t_stack *stack)
{
	if (stack->size <= 7)
		small_sort(stack, _compare_asc);
	else if (stack->size <= 14)
		medium_sort(stack);
	else
		large_sort(stack);
}
