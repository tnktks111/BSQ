# ifndef DEV_H
#define DEV_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_board_info
{
	int **board;
	int row;
	int col;
	int cur_max;
	int coordinates[3]; //1...row, 2...col, 3...edge len
} t_board_info;

typedef struct s_basic_info
{
	char *str;
	char empty;
	char obstacle;
	char full;
	int row;
	int col;
} t_basic_info;

typedef struct s_node
{
	int data;
	struct s_node *next;
} t_node;

#define BUF_SIZE 4096
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int file_size(char *file);
char *file_read(char *file);

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

int validation(char *str);
int is_printable(char c);
int check_head(char *str);
int check_size(char *str);
int check_row(char *row, char empty, char obstacle, int size);

int	**compute_histograms(t_board_info *info);
void	free_board(int **board, int rows);
void	print_board(int **board, int row, int col);

int solve_histgram(int *histgram, int size);


#include <stdio.h>

#endif