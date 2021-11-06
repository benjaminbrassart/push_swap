/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:29:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/04 10:14:55 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

typedef enum e_order
{
	ASC = 0,
	DESC
}	t_order;

t_comparator	get_cmp(t_order order);

int				get_median(t_stack const *stack);

void			sort(unsigned int msb);

int				small_sort(t_stack *stack, t_order order);

int				medium_sort(t_stack *stack, t_order order);

int				large_sort(t_stack *stack, t_order order);

#endif
