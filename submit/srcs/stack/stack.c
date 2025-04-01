/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:16:09 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:03 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int	insert_bf_head(t_node **head, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		return (-1);
	if (*head == NULL)
	{
		*head = new_node;
		return (0);
	}
	new_node->next = *head;
	*head = new_node;
	return (0);
}

int	delete_head(t_node **head)
{
	t_node	*tmp;

	if (*head == NULL)
		return (-1);
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return (0);
}

int	is_empty(t_node **stack)
{
	return (*stack == NULL);
}

void	push(t_node **stack, int data)
{
	insert_bf_head(stack, data);
}

int	pop(t_node **stack)
{
	t_node	*tmp;
	int		data;

	if (is_empty(stack))
	{
		return (-1);
	}
	tmp = *stack;
	data = tmp->data;
	delete_head(stack);
	return (data);
}
