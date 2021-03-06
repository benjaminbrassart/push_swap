/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:29:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 09:06:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ft_def.h"
# include "stack.h"

typedef enum e_order
{
	ASC = 0,
	DESC
}	t_order;

t_comparator	get_cmp(t_order order);

int				get_median(t_stack *stack);

void			sort(unsigned int msb);

t_bool			sort_small(int median);

#endif
