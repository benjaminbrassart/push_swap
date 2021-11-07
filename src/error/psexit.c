/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:09:07 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/07 11:39:03 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "pserror.h"
#include "stack.h"
#include "util.h"
#include <stdlib.h>

static char const	*_get_errno_message(t_errno err)
{
	struct s_errno_lt const	*_errno = g_errno();
	int						i;

	i = 0;
	while (_errno[i].errno != err && _errno[i].message)
		++i;
	return (_errno[i].message);
}

void	psexit(t_errno err)
{
	stack_delete(&_stacks()->a, FT_NULL);
	stack_delete(&_stacks()->b, FT_NULL);
	if (err != NONE)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(_get_errno_message(err), 2);
		exit(1);
	}
	exit(0);
}
