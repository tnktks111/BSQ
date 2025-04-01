#define MAX_DATA 1000

typedef struct s_stack
{
	int arr[MAX_DATA];
	int top;
} t_stack;

typedef struct s_board_info
{
	int **board;
	int row;
	int col;
} t_board_info;

int push(t_stack *stack, int input)
{
	if (stack->top < MAX_DATA)
	{
		stack->arr[stack->top] = input;
		stack->top++;
		return 0;
	}
	else
		return (-1);
}

int pop(t_stack *stack)
{
	if (stack->top > 0)
	{
		stack->top--;
		return (stack->arr[stack->top]);
	}
	else
		return (-1);
}
void init_stack(t_stack *stack)
{
	stack->top = 0;
}

int ft_strlen(char *str)
{
	char *tail = str;
	while (*tail)
	{
		tail++;
	}
	return (tail - str);
}

int max(int s1, int s2)
{
	if (s1 > s2)
		return s1;
	return s2;
}

int min(int s1, int s2)
{
	if (s1 > s2)
		return s2;
	return s1;
}

int calculate_square(int height, int width)
{
	int small = min(height, width);
	return (small * small);
}

#include <stdio.h>
int main()
{
	int heights[27] = {7,7,7,7,2,7,7,7,7,7,7,7,4,7,7,1,7,7,7,7,7,7,7,7,7,7,7};
	int max_area = 0;
	int i = 0;
	int len = 27;
	int height;
	int width;
	t_stack stack;
	init_stack(&stack);
	while (i < len)
	{
		while (stack.top != 0 && heights[stack.arr[stack.top - 1]] >= heights[i])
		{
			height = heights[pop(&stack)];
			if (stack.top > 0)
				width = i - stack.arr[stack.top - 1] - 1;
			else
				width = i;
			max_area = max(max_area, calculate_square(height, width));
		}
		push(&stack, i++);
	}
	while (stack.top > 0) {
		int height = heights[pop(&stack)];
		if (stack.top > 0)
			width = len - stack.arr[stack.top - 1] - 1;
		else 
			width = len;
		max_area = max(max_area, calculate_square(height, width));
	}
	printf("%d", max_area);
	return (max_area);
}
