#include "dev.h"

void solve_histgram_map(t_board_info *board_info)
{
	int i = 0;
	int row = board_info->row;
	int col = board_info->col;
	while (i < row)
	{
		solve_histgram_row(board_info->board[i], col, board_info, i);
		i++;
	}
}

void solve_histgram_row(int *histgram, int size, t_board_info *info, int row)
{
    int area = 0;
    int i = 0;
    int height;
    int width;
    int left_idx;
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
                
            area = calculate_square(height, width);
            if (area > info->cur_max)
            {
                info->cur_max = area;
                left_idx = is_empty(&stack) ? 0 : stack->data + 1;
                info->coordinates[0] = row - height + 1;
                info->coordinates[1] = left_idx;
                info->coordinates[2] = ft_min(height, width);
            }
        }
        push(&stack, i++);
    }
    
    // スタックが空になるまで処理
    while (!is_empty(&stack))
    {
        height = histgram[pop(&stack)];
        left_idx = is_empty(&stack) ? 0 : stack->data + 1;
        width = size - left_idx;
        
        area = calculate_square(height, width);
        if (area > info->cur_max)
        {
            info->cur_max = area;
            info->coordinates[0] = row - height + 1;
            info->coordinates[1] = left_idx;
            info->coordinates[2] = ft_min(height, width);
        }
    }
}