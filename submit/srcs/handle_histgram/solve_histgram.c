/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:15:51 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:45:48 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

void	solve_hist_map(t_g_info *board_info)
{
	long long	i;
	long long	r;
	long long	c;

	i = 0;
	r = board_info->r;
	c = board_info->c;
	while (i < r)
	{
		solve_hist_r(board_info->grid[i], c, board_info, i);
		i++;
	}
}

void	solve_hist_r(long long *hist, long long s, t_g_info *info, long long r)
{
	long long	i;
	long long	height;
	long long	width;
	long long	left_idx;
	t_node		*stack;

	i = -1;
	stack = NULL;
	while (++i <= s)
	{
		while (!is_empty(&stack) && (i == s || hist[stack->data] >= hist[i]))
		{
			height = hist[pop(&stack)];
			width = get_width(i, &stack);
			if (calculate_square(height, width) > info->cur_max)
			{
				info->cur_max = calculate_square(height, width);
				left_idx = get_left_index(&stack);
				ft_multiassign(info->coordinates, r - height + 1, left_idx,
					ft_min(height, width));
			}
		}
		if (i < s)
			push(&stack, i);
	}
}

long long	get_left_index(t_node **stack)
{
	if (is_empty(stack))
		return (0);
	return ((*stack)->data + 1);
}

long long	get_width(long long i, t_node **stack)
{
	if (!is_empty(stack))
		return (i - (*stack)->data - 1);
	return (i);
}
