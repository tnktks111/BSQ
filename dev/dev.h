#ifndef DEV_H
#define DEV_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_board_info
{
	int **board;
	int row;
	int col;
	int cur_max;
	int coordinates[4];
} t_board_info;

typedef struct s_node
{
	int data;
	struct s_node *next;
} t_node;

t_node *create_node(int data);
int insert_bf_head(t_node **head, int data);
int delete_head(t_node **head);
int is_empty(t_node** stack);
void push(t_node **stack, int data);
int pop(t_node** stack);

int ft_max(int s1, int s2);
int ft_min(int s1, int s2);
void	ft_putstr(char *str);
int ft_strlen(char *str);
int calculate_square(int height, int width);

#include <stdio.h>

#endif