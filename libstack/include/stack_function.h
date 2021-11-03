/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:54:54 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/28 23:03:32 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_FUNCTION_H
# define STACK_FUNCTION_H

# include "stack_type.h"

/**
 * Create a new stack element with a specific value
 * 
 * @param value the value contained in the new element
 * @return a pointer to the created element, or NULL if malloc() failed
 */
t_stack_elem	*stack_elem_new(int value);

/**
 * Add an element at the end of a stack
 * 
 * @param stack the stack to add the element to
 * @param elem the element to add
 */
void			stack_backpush(t_stack *stack, t_stack_elem *elem)
				__attribute__((nonnull(1, 2)));

/**
 * Add an element at the start of a stack
 * 
 * @param stack the stack to add the element to
 * @param elem the element to add
 */
void			stack_frontpush(t_stack *stack, t_stack_elem *elem)
				__attribute__((nonnull(1, 2)));

/**
 * Delete a stack's elements
 * 
 * @param stack the stack to delete the elements
 * @param del_fn the delete function, will use free() if set to NULL
 */
void			stack_delete(t_stack *stack, void (*del_fn)(t_stack_elem *))
				__attribute__((nonnull(1)));

/**
 * Fill a stack with values
 * 
 * @param stack the stack to fill
 * @param values a pointer to the first value to add
 * @param length the number of elements to add
 * @return 0 if an error occurred
 */
int				stack_fill(t_stack *stack, int *values, unsigned int length)
				__attribute__((nonnull(1, 2)));

/**
 * Execute a function to every elements in a stack
 * 
 * @param stack the stack to go through
 * @param f the function to execute, returning 0 if it needs to stop
 */
void			stack_foreach(t_stack *stack, int (*f)(t_stack_elem *))
				__attribute__((nonnull(1)));

/**
 * Check whether a stack if sorted or not
 * 
 * @param stack the stack to check
 * @param cmp the comparison function
 */
int				stack_issorted(t_stack *stack, int (*cmp)(int, int))
				__attribute__((nonnull(1, 2)));

/**
 * Remove the last element of a stack and return it
 * 
 * @param stack the stack to remove the element from
 * @return the last element of the stack if not NULL, NULL otherwise
 */
t_stack_elem	*stack_pop(t_stack *stack)
				__attribute__((nonnull(1)));

/**
 * Remove the first element of a stack and return it
 * 
 * @param stack the stack to remove the element from
 * @return the first element of the stack if not NULL, NULL otherwise
 */
t_stack_elem	*stack_shift(t_stack *stack)
				__attribute__((nonnull(1)));

#endif
