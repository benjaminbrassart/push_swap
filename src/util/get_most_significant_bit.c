/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_most_significant_bit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:48:56 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/04 09:51:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned int	get_most_significant_bit(int n)
{
	unsigned int	bit;

	if (n == 0)
		return (0);
	bit = sizeof (n) * 8 - 1;
	while (!(n & (1 << bit)))
		--bit;
	return (bit);
}
