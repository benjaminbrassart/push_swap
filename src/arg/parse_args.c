/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:45:37 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 18:16:02 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_stdlib.h"

int	*parse_args(int argc, char *argv[], t_size *len_ptr)
{
	int	*values;
	int	n;

	values = ft_calloc(argc - 1, sizeof (*values));
	if (values)
	{
		n = 0;
		while (n < argc - 1)
		{
			values[n] = ft_atoi(argv[n + 1]);
			++n;
		}
		*len_ptr = (t_size)n;
	}
	return (values);
}
