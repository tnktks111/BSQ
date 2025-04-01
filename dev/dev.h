#ifndef DEV_H
#define DEV_H

#include <stdlib.h>

typedef struct s_board_info
{
	int **board;
	int row;
	int col;
} t_board_info;

int ft_max(int s1, int s2);
int ft_min(int s1, int s2);
void	ft_putstr(char *str);
int ft_strlen(char *str);
int calculate_square(int height, int width);

#endif