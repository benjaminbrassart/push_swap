/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:03:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/01 23:33:15 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPERATION_H
# define STACK_OPERATION_H

# include "stack_type.h"

/**
 * Push the first element of a stack to the top of another
 * 
 * @param sender the stack that will lose a element
 * @param receiver the stack that will gain an element
 */
void	stack_push(t_stack *sender, t_stack *receiver)
		__attribute__((nonnull(1, 2)));

/**
 * Shift up all the elements of a stack, and the first element becomes the last
 * 
 * @param stack the stack to rotate
 */
void	stack_rotate(t_stack *stack)
		__attribute__((nonnull(1)));

/**
 * Shift down all the elements of a stack, and the last element becomes the first
 * 
 * @param stack the stack to reverse rotate
 */
void	stack_reverse_rotate(t_stack *stack)
		__attribute__((nonnull(1)));

/**
 * Swap the first two elements of a stack
 * 
 * @param stack the stack to swap
 */
void	stack_swap(t_stack *stack)
		__attribute__((nonnull(1)));

#endif
