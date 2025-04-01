#include <stdlib.h>
#include "dev.h"
#include<stdio.h>
int	**compute_histograms(t_board_info *info)
{
	int	**heights;
	int	i;
	int	j;

	i = 0;
	heights = (int **)malloc(sizeof(int *) * info->row);
	if (!heights)
		return (NULL);
	while (i < info->row)
	{
		j = 0;
		heights[i] = (int *)malloc(sizeof(int) * info->col);
		if (!heights[i])
			return (NULL);
		while (j < info->col)
		{
			if (info->board[i][j] == 0)
				heights[i][j] = 0;
			else if (i == 0)
				heights[i][j] = 1;
			else
				heights[i][j] = heights[i - 1][j] + 1;
			j++;
		}
		i++;
	}
	return (heights);
}


void	free_board(int **board, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	print_board(int **board, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%d ", board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// int	main(void)
// {
// 	t_board_info	info;
// 	int				**heights;
// 	int				i;

// 	info.row = 3;
// 	info.col = 5;
// 	info.board = (int **)malloc(sizeof(int *) * info.row);
// 	i = 0;
// 	while (i < info.row)
// 	{
// 		info.board[i] = (int *)malloc(sizeof(int) * info.col);
// 		i++;
// 	}
// 	info.board[0][0] = 1;
// 	info.board[0][1] = 0;
// 	info.board[0][2] = 0;
// 	info.board[0][3] = 0;
// 	info.board[0][4] = 1;
// 	info.board[1][0] = 0;
// 	info.board[1][1] = 1;
// 	info.board[1][2] = 1;
// 	info.board[1][3] = 1;
// 	info.board[1][4] = 1;
// 	info.board[2][0] = 1;
// 	info.board[2][1] = 0;
// 	info.board[2][2] = 1;
// 	info.board[2][3] = 0;
// 	info.board[2][4] = 1;
// 	printf("Input board:\n");
// 	print_board(info.board, info.row, info.col);
// 	heights = compute_histograms(&info);
// 	if (!heights)
// 	{
// 		printf("malloc error\n");
// 		return (1);
// 	}
// 	printf("\nComputed histograms:\n");
// 	print_board(heights, info.row, info.col);
// 	free_board(info.board, info.row);
// 	free_board(heights, info.row);
// 	return (0);
// }