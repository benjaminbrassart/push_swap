/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_highest_most_significant_bit.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:02:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/04 10:05:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned int	get_highest_most_significant_bit(int *values, unsigned int n)
{
	unsigned int	max;
	unsigned int	msb;

	max = 0;
	while (n--)
	{
		msb = get_most_significant_bit(values[n]);
		if (msb > max)
			max = msb;
	}
	return (max);
}
