/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:01:14 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 10:03:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "util.h"

static int	_cmp_asc(int a, int b)
{
	return (a < b);
}

static int	_cmp_desc(int a, int b)
{
	return (a > b);
}

t_comparator	get_cmp(t_order order)
{
	if (order == ASC)
		return (_cmp_asc);
	return (_cmp_desc);
}
