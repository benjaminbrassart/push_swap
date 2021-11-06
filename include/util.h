/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:26:40 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/04 10:11:41 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "ft_def.h"
# include "stack_type.h"

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

t_stacks		*_stacks(void);

t_stack			*opposite_stack(t_stack *stack)
				__attribute__((nonnull(1)));

/**
 * Print the element of a stack
 * 
 * @param stack the stack to print
 */
void			stack_print(t_stack const *stack)
				__attribute__((nonnull(1)));

/**
 * Map a stack and replace each number by its order
 * 
 * @param stack the stack to map
 * @return true if the mapping went flawlessly, false otherwise
 */
t_bool			stack_remap(t_stack *stack)
				__attribute__((nonnull(1)));

/**
 * Swap two integers
 * 
 * @param a a pointer to the first integer
 * @param b a pointer to the second integer
 */
void			swap_i(int *a, int *b)
				__attribute__((nonnull(1, 2)));

/**
 * Get the most significant bit of a number
 * 
 * @param n the number
 * @return the position of the most significant bit that equals 1
 */
unsigned int	get_most_significant_bit(int n);

/**
 * Get the highest most significant bit of a sequence of numbers
 * 
 * @param values the sequence of numbers
 * @param n the number of values
 * @return the highest most significant bit that equals 1
 */
unsigned int	get_highest_most_significant_bit(int *values, unsigned int n)
				__attribute__((nonnull(1)));

#endif
