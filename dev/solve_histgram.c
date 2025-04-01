#include "dev.h"

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

int main()
{
	int histgram[27] = {7,7,7,7,2,7,7,7,7,7,7,7,4,7,7,1,7,7,7,7,7,7,7,7,7,7,7};
	int size = 27;
	printf("%d", solve_histgram(histgram, size));
	return (0);
}
