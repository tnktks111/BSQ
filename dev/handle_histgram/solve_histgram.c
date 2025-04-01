#include "dev.h"

//ここに引数"t_board_info *info"を追加して書き込む処理
int solve_histgram(int *histgram, int size)
{
	int max_area = 0;
	int i = 0;
	int height;
	int width;
	t_node *stack = NULL;
	while (i < size)
	{
		while (!is_empty(&stack) && histgram[stack->data] >= histgram[i])
		{
			height = histgram[pop(&stack)];
			if (!is_empty(&stack))
				width = i - stack->data - 1;
			else
				width = i;
			max_area = ft_max(max_area, calculate_square(height, width));
			/* if (area > info->cur_max)
			{
				info->cur_max = area;
				info->coordinates[0] = row - height + 1;
				info->coordinates[1] = stack->data + 1;
				info->coordinates[2] = row - height + ft_min(height. width);
				info->coordinates[3] = stack->data + ft_min(height, width);
			}*/
		}
		push(&stack, i++);
	}
	while (!is_empty(&stack))
	{
		height = histgram[pop(&stack)];
		if (!is_empty(&stack))
			width = size - stack->data - 1;
		else 
			width = size;
		max_area = ft_max(max_area, calculate_square(height, width));
	}
	return (max_area);
}

// int main()
// {
// 	int histgram[6] = {2, 1, 5, 6, 1, 2};
// 	int size = 6;
// 	printf("%d", solve_histgram(histgram, size));
// 	return (0);
// }
