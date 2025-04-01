#include "dev.h"
#include <stdio.h>
#include <stdlib.h>

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

t_g_info	*parse_map(char **lines, t_basic_info *basic_info)
{
	t_g_info *info;
	int i;

	i = 0;
	info = malloc(sizeof(t_g_info));
	if (!info)
		return (NULL);
	info->row = basic_info->row;
	info->col = basic_info->col;
	info->cur_max = 0;
	info->coordinates[0] = 0;
	info->coordinates[1] = 0;
	info->coordinates[2] = 0;
	info->grid = malloc(sizeof(int *) * info->row);
	if (!info->grid)
		return (NULL);
	while (i < info->row)
	{
		info->grid[i] = malloc(sizeof(int) * info->col);
		if (!info->grid[i])
			return (NULL);
		fill_board_row(info->grid[i], lines[i], info->col, basic_info->empty);
		i++;
	}
	return (info);
}
