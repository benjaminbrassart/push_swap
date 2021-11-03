/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:26:40 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/02 00:03:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "stack_type.h"

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

t_stacks	*_stacks(void);

t_stack		*opposite_stack(t_stack *stack)
			__attribute__((nonnull(1)));

void		swap_i(int *a, int *b);

#endif
