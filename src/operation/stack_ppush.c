/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ppush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:17:13 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/03 14:04:11 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "stack_operation.h"

void	stack_ppush(t_stack *sender, t_stack *receiver)
{
	stack_push(sender, receiver);
	ft_printf("p%c\n", receiver->id);
}
