/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:37:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:02:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

# include "ft_def.h"

t_bool	check_args(int argc, char *argv[]);

t_bool	check_duplicate(int *values, t_size len);

int		*parse_args(int argc, char *argv[], t_size *len_ptr);

#endif
