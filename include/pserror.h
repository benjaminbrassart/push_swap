/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pserror.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:02:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 08:15:49 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSERROR_H
# define PSERROR_H

# define RED "\033[31m"
# define RESET "\033[0m"

# define ERROR_MALLOC_FAILED "Memory allocation failed."
# define ERROR_DUPLICATE_VALUES "There are duplicate arguments."
# define ERROR_NOT_INTEGER "An argument is not an integer."
# define ERROR_INT_OVERFLOW "An argument overflows int limits."
# define ERROR_INT_UNDERFLOW "An argument underflows int limits."
# define ERROR_INVALID_OPERATION "Invalid operation."

void	print_error(char const *message)
		__attribute__((nonnull));

#endif
