#include "dev.h"

//出力すべき文字列を生成
void	convert(t_basic_info *basic_info, t_g_info *board_info)
{
	int	i;
	int	j;

	i = board_info->coordinates[0];
	while (i < board_info->coordinates[0] + board_info->coordinates[2])
	{
		j = board_info->coordinates[1];
		while (j < board_info->coordinates[1] + board_info->coordinates[2])
			basic_info->lines[i][j++] = basic_info->full;
		i++;
	}
}
