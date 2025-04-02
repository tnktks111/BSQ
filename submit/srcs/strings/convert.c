/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:16:43 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:07 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

//出力すべき文字列を生成
void	convert(t_basic_info *basic_info, t_g_info *board_info)
{
	long long	i;
	long long	j;

	i = board_info->coordinates[0];
	while (i < board_info->coordinates[0] + board_info->coordinates[2])
	{
		j = board_info->coordinates[1];
		while (j < board_info->coordinates[1] + board_info->coordinates[2])
			basic_info->lines[i][j++] = basic_info->full;
		i++;
	}
}
