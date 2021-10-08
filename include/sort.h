/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:29:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 19:55:11 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

# ifdef OPS_COUNT
#  undef OPS_COUNT
# endif

# define OPS_COUNT 11

static const char	*g_ops[] = {"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr",
	"rra", "rrb", "rrr"};

void	sort(t_stack *stack);

void	small_sort(t_stack *stack, int (*cmp)(int, int));

void	medium_sort(t_stack *stack);

void	large_sort(t_stack *stack);

#endif