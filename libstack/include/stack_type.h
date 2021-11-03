/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:01:28 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 09:44:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TYPE_H
# define STACK_TYPE_H

/**
 * A function that compares two integers
 * 
 * @param a the first integer
 * @param b the second integer
 * @return a non-0 value if a and b are in the correct order, 0 otherwise
 */
typedef int	(*t_comparator)(int a, int b);

/**
 * A doubly linked list holding a value
 * 
 * @param value the value contained in the element
 * @param prev a pointer to the previous link
 * @param next a pointer to the next link
 */
typedef struct s_stack_elem
{
	int					value;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
}	t_stack_elem;

/**
 * A doubly linked list wrapper holding its first and last element, as well as
 * its number of elements
 * 
 * @param id the id of the stack, for debugging purposes
 * @param first a pointer to the first element of the stack
 * @param last a pointer to the last element of the stack
 * @param size the number of elements in the stack
 */
typedef struct s_stack
{
	int				id;
	t_stack_elem	*first;
	t_stack_elem	*last;
	unsigned int	size;
}	t_stack;

#endif
