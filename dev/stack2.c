#include "dev.h"

typedef struct s_node
{
	int data;
	struct s_node *next;
} t_node;

t_node *create_node(int data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

int insert_bf_head(t_node **head, int data)
{
	t_node *new_node;

	new_node = create_node(data);
	if (!new_node)
		return -1;
	if (*head == NULL)
	{
		*head = new_node;
		return (0);
	}
	new_node->next = *head;
	*head = new_node;
	return (0);
}

int delete_head(t_node **head)
{
	if (*head == NULL)
		return -1;
	t_node *tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return 0;
}

int is_empty(t_node** stack)
{
	return (*stack == NULL);
}

void push(t_node **stack, int data)
{
	insert_bf_head(stack, data);
}

int pop(t_node** stack)
{
	if (is_empty(stack))
	{
		return (-1);
	}
	t_node *tmp = *stack;
	int data = tmp->data;
	delete_head(stack);
	return (data);
}


#include <stdio.h>
int main()
{
	int heights[27] = {7,7,7,7,2,7,7,7,7,7,7,7,4,7,7,1,7,7,7,7,7,7,7,7,7,7,7};
	int max_area = 0;
	int i = 0;
	int len = 27;
	int height;
	int width;
	t_node *stack = NULL;
	while (i < len)
	{
		while (!is_empty(&stack) && heights[stack->data] >= heights[i])
		{
			height = heights[pop(&stack)];
			if (!is_empty(&stack))
				width = i - stack->data - 1;
			else
				width = i;
			max_area = ft_max(max_area, calculate_square(height, width));
		}
		push(&stack, i++);
	}
	while (!is_empty(&stack))
	{
		height = heights[pop(&stack)];
		if (!is_empty(&stack))
			width = len - stack->data - 1;
		else 
			width = len;
		max_area = ft_max(max_area, calculate_square(height, width));
	}
	printf("%d", max_area);
	return (max_area);
}
