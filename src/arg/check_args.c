/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:40:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/08 18:12:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include "ft_stdio.h"
#include <stdlib.h>

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		exit(0);
	i = 0;
	while (++i < argc)
	{
		if (!check_arg_int(argv[i]))
			ft_putendl_fd("Error: an argument is not an integer.", 2);
		else if (!check_arg_overflow(argv[i]))
			ft_putendl_fd("Error: an argument overflows int limit.", 2);
		else
			continue ;
		exit(1);
	}
}
