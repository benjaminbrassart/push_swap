/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 06:38:33 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 08:14:51 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "pserror.h"

void	print_error(char const *err)
{
	ft_dputs(2, RED);
	ft_dputs(2, err);
	ft_dputnl(2, RESET);
}
