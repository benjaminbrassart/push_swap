/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pserror.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:02:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 16:59:52 by bbrassar         ###   ########.fr       */
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

static const struct s_errno_lt	g_errno[] = {
	{MALLOC_FAILED, "memory allocation failed."},
	{DUPLICATE_VALUES, "there are duplicate arguments."},
	{NOT_INTEGER, "an argument is not an integer."},
	{INT_OVERFLOW, "an argument overflows int limit."},
	{INVALID_OPERATION, "invalid operation."},
	{NONE, FT_NULL}
};

void	psexit(t_errno errno) __attribute__((noreturn));

#endif
