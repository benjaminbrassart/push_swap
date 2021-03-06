/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opposite_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:45:28 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:32:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "util.h"

t_stack	*opposite_stack(t_stack *stack)
{
	if (stack->id == 'a')
		return (get_stack('b'));
	return (get_stack('a'));
}
