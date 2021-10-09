/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:29:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 16:44:57 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

# ifdef OPS_COUNT
#  undef OPS_COUNT
# endif

void	sort(t_stack *stack);

void	small_sort(t_stack *stack, int (*cmp)(int, int));

void	medium_sort(t_stack *stack);

void	large_sort(t_stack *stack);

#endif
