#include "dev.h"

typedef struct s_node
{
	int data;
	t_node *next;
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
	t_node *tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return 0;
}