/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:31:57 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 15:28:49 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "pserror.h"
#include "stack.h"
#include <stdlib.h>

void	stack_fill(int *values, t_size len)
{
	t_size			i;
	t_stack_elem	*e;

	i = -1;
	while (++i < len)
	{
		e = stack_elem_new(values[i]);
		if (!e)
		{
			free(values);
			stack_delete(&_stacks()->a);
			psexit(MALLOC_FAILED);
		}
		stack_backpush(&_stacks()->a, e);
	}
	free(values);
}
