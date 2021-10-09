/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:09:07 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/09 15:58:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "pserror.h"
#include <stdlib.h>

static char const	*get_errno_message(t_errno err)
{
	int	i;

	i = 0;
	while (g_errno[i].errno != err && g_errno[i].message)
		++i;
	return (g_errno[i].message);
}

void	psexit(t_errno err)
{
	if (err != NONE)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(get_errno_message(err), 2);
		exit(1);
	}
	exit(0);
}
