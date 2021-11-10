/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_errno.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:54:03 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/10 11:37:03 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"
#include "pserror.h"

struct s_errno_lt const	*g_errno(void)
{
	static struct s_errno_lt const	errno[] = {
	{MALLOC_FAILED, "Memory allocation failed"},
	{DUPLICATE_VALUES, "There are duplicate arguments"},
	{NOT_INTEGER, "An argument is not an integer"},
	{INT_OVERFLOW, "An argument overflows int limit"},
	{INT_UNDERFLOW, "An argument underflows int limit"},
	{INVALID_OPERATION, "Invalid operation"},
	{NONE, FT_NULL}
	};

	return (errno);
}
