/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:44:18 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 14:35:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FUNCTIONS_H
# define FT_PRINTF_FUNCTIONS_H

# include <stdarg.h>
# include <stdlib.h>
# include "ft_printf_options.h"

typedef struct s_printer
{
	int	chr;
	int	(*fn)(t_opt *, va_list);
}	t_printer;

void		ft_putstr_fn(char const *s, int (*fn)(int));

int			ft_print_char(t_opt *opt, va_list args)
			__attribute__((nonnull(1)));

int			ft_print_string(t_opt *opt, va_list args)
			__attribute__((nonnull(1)));

int			ft_print_pointer(t_opt *opt, va_list args)
			__attribute__((nonnull(1)));

int			ft_print_int(t_opt *opt, va_list args)
			__attribute__((nonnull(1)));

int			ft_print_uint(t_opt *opt, va_list args)
			__attribute__((nonnull(1)));

int			ft_print_hex_low(t_opt *opt, va_list args)
			__attribute__((nonnull(1)));

int			ft_print_hex_up(t_opt *opt, va_list args)
			__attribute__((nonnull(1)));

int			ft_print_raw(t_opt *opt, int chr)
			__attribute__((nonnull(1)));

t_printer	*ft_get_printers(void);

t_printer	ft_get_printer(int chr);

#endif
