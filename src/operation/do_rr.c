/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:39:22 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/02 00:02:41 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_bool	do_rr(void)
{
	t_bool const	ra = do_ra();
	t_bool const	rb = do_rb();

	return (ra || rb);
}
