/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pserror.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:02:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/20 08:31:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSERROR_H
# define PSERROR_H

# include "ft_def.h"

typedef enum e_errno
{
	NONE = 0,
	MALLOC_FAILED,
	DUPLICATE_VALUES,
	NOT_INTEGER,
	INT_OVERFLOW,
	INVALID_OPERATION,
}	t_errno;

struct s_errno_lt
{
	t_errno		errno;
	char const	*message;
};

static struct s_errno_lt const	g_errno[] = {
	{MALLOC_FAILED, "Memory allocation failed"},
	{DUPLICATE_VALUES, "There are duplicate arguments"},
	{NOT_INTEGER, "An argument is not an integer"},
	{INT_OVERFLOW, "An argument overflows int limit"},
	{INVALID_OPERATION, "Invalid operation"},
	{NONE, FT_NULL}
};

void	psexit(t_errno errno) __attribute__((noreturn));

#endif
