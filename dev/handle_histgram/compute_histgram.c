#include "dev.h"

void	compute_histograms(t_g_info *info)
{
	int	**heights;
	int	i;
	int	j;

	i = 0;
	heights = (int **)malloc(sizeof(long long *) * info->row);
	if (!heights)
		return ;
	while (i < info->row)
	{
		j = 0;
		heights[i] = (int *)malloc(sizeof(long long) * info->col);
		if (!heights[i])
			return ;
		while (j < info->col)
		{
			if (info->grid[i][j] == 0)
				heights[i][j] = 0;
			else if (i == 0)
				heights[i][j] = 1;
			else
				heights[i][j] = heights[i - 1][j] + 1;
			j++;
		}
		i++;
	}
	info->grid = heights;
}
