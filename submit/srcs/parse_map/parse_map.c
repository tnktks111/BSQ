/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:16:03 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:01 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

void	fill_board_r(long long *dest, char *src, long long len, char empty)
{
	long long	j;

	j = 0;
	while (j < len)
	{
		dest[j] = (src[j] == empty);
		j++;
	}
}

t_g_info	*parse_map(char **lines, t_basic_info *basic_info)
{
	t_g_info	*info;
	long long	i;

	i = 0;
	info = malloc(sizeof(t_g_info));
	if (!info)
		return (NULL);
	info->r = basic_info->r;
	info->c = basic_info->c;
	info->cur_max = 0;
	info->coordinates[0] = 0;
	info->coordinates[1] = 0;
	info->coordinates[2] = 0;
	info->grid = malloc(sizeof(long long *) * info->r);
	if (!info->grid)
		return (NULL);
	while (i < info->r)
	{
		info->grid[i] = malloc(sizeof(long long) * info->c);
		if (!info->grid[i])
			return (NULL);
		fill_board_r(info->grid[i], lines[i], info->c, basic_info->empty);
		i++;
	}
	return (info);
}
