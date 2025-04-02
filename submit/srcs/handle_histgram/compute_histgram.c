/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_histgram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:15:46 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:15:48 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

void	compute_histograms(t_g_info *info)
{
	long long	**heights;
	long long	i;
	long long	j;

	i = -1;
	heights = (long long **)malloc(sizeof(long long *) * info->r);
	if (!heights)
		return ;
	while (++i < info->r)
	{
		j = -1;
		heights[i] = (long long *)malloc(sizeof(long long) * info->c);
		if (!heights[i])
			return ;
		while (++j < info->c)
		{
			if (info->grid[i][j] == 0)
				heights[i][j] = 0;
			else if (i == 0)
				heights[i][j] = 1;
			else
				heights[i][j] = heights[i - 1][j] + 1;
		}
	}
	info->grid = heights;
}
