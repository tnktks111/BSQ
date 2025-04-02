/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:53:28 by ttanaka           #+#    #+#             */
/*   Updated: 2025/04/02 11:53:30 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

void	push(t_node **stack, long long data)
{
	insert_bf_head(stack, data);
}

long long	pop(t_node **stack)
{
	t_node		*tmp;
	long long	data;

	if (is_empty(stack))
		return (-1);
	tmp = *stack;
	data = tmp->data;
	delete_head(stack);
	return (data);
}
