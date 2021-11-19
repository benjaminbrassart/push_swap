/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ppush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:17:13 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 07:10:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_operation.h"
#include <unistd.h>

void	stack_ppush(t_stack *sender, t_stack *receiver)
{
	char const	s[3] = {'p', receiver->id, '\n'};

	stack_push(sender, receiver);
	write(1, s, 3);
}
