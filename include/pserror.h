/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pserror.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:02:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/20 08:54:36 by bbrassar         ###   ########.fr       */
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

struct s_errno_lt const	*g_errno(void);

void					psexit(t_errno errno)
						__attribute__((noreturn));

#endif
