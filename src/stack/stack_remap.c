/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_remap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:49:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 14:43:33 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "stack.h"
#include <stdlib.h>

static int	_get_position(t_stack *stack, int value)
{
	t_stack_elem	*iter_elem;
	int				position;

	iter_elem = stack->first;
	position = 0;
	while (iter_elem)
	{
		if (value > iter_elem->value)
			++position;
		iter_elem = iter_elem->next;
	}
	return (position);
}

static void	_replace_values(t_stack *original_stack, t_stack *new_stack)
{
	t_stack_elem	*original_elem;
	t_stack_elem	*new_elem;

	original_elem = original_stack->first;
	new_elem = new_stack->first;
	while (original_elem && new_elem)
	{
		original_elem->value = new_elem->value;
		original_elem = original_elem->next;
		new_elem = new_elem->next;
	}
}

static t_bool	_create_elem(t_stack *stack, t_stack *new_stack, int value)
{
	t_stack_elem *const	new_elem = malloc(sizeof (*new_elem));

	if (new_elem)
	{
		new_elem->value = _get_position(stack, value);
		stack_backpush(new_stack, new_elem);
	}
	return (new_elem == FT_NULL);
}

t_bool	stack_remap(t_stack *stack)
{
	t_stack *const	new_stack = malloc(sizeof (*new_stack));
	t_stack_elem	*iter_elem;
	t_bool			has_error;

	has_error = false;
	if (new_stack)
	{
		new_stack->size = 0;
		new_stack->first = FT_NULL;
		new_stack->last = FT_NULL;
		iter_elem = stack->first;
		while (iter_elem && !has_error)
		{
			has_error = _create_elem(stack, new_stack, iter_elem->value);
			iter_elem = iter_elem->next;
		}
		if (!has_error)
			_replace_values(stack, new_stack);
		stack_delete(new_stack, FT_NULL);
		free(new_stack);
	}
	return (!(new_stack == FT_NULL || has_error));
}
