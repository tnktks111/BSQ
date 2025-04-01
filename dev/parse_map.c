#include <stdlib.h>
#include <stdio.h>

//iran
typedef struct s_board_info
{
	int **board;
	int row;
	int col;
}	t_board_info;


//iran
int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

void	fill_board_row(int *dest, char *src, int len, char empty)
{
	int	j;

	j = 0;
	while (j < len)
	{
		dest[j] = (src[j] == empty);
		j++;
	}
}

t_board_info	*parse_map(char **lines, int row_count, int col_count)
{
	t_board_info	*info;
	int				i;
	char			empty;

	i = 0;
	empty = lines[0][ft_strlen(lines[0]) - 3];
	info = malloc(sizeof(t_board_info));
	if (!info)
		return (NULL);
	info->row = row_count;
	info->col = col_count;
	info->board = malloc(sizeof(int *) * row_count);
	if (!info->board)
		return (NULL);
	while (i < row_count)
	{
		info->board[i] = malloc(sizeof(int) * col_count);
		if (!info->board[i])
			return (NULL);
		fill_board_row(info->board[i], lines[i + 1], col_count, empty);
		i++;
	}
	return (info);
}

//iran kokkara
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

void	free_board(t_board_info *info)
{
	int	i;

	i = 0;
	while (i < info->row)
	{
		free(info->board[i]);
		i++;
	}
	free(info->board);
	free(info);
}

int	main(void)
{
	// マップ定義：1行目が仕様行、2〜4行目がマップ
	char *lines[] = {
		"3.ox",       // 3行, '.'が空白、'o'が障害物
		".o..o",
		"ooooo",
		".o.o.",
		NULL
	};

	int	row = 3;
	int	col = 5;

	t_board_info *info = parse_map(lines, row, col);
	if (!info)
	{
		printf("Error: failed to parse map.\n");
		return (1);
	}

	printf("Parsed board (1=empty, 0=obstacle):\n");
	print_board(info->board, info->row, info->col);

	free_board(info);
	return (0);
}