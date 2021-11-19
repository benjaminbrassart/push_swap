/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_highest_most_significant_bit.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:02:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:59:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned int	get_highest_most_significant_bit(int *values, unsigned int n)
{
	int	comb;

	comb = 0;
	while (n--)
		comb |= values[n];
	return (get_most_significant_bit(comb));
}
