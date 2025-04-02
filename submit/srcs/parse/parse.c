/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:15:59 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:45:57 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

//正常動作で0、それ以外は1を返す
int	parse(char *file_path)
{
	char			*str;
	t_basic_info	*basic_info;
	t_g_info		*board_info;

	str = file_read(file_path);
	if (!str)
		return (1);
	basic_info = (t_basic_info *)malloc(sizeof(t_basic_info));
	if (validation(str, basic_info))
		return (1);
	basic_info->lines = ft_split(str, basic_info->r, basic_info->c);
	board_info = parse_map(basic_info->lines, basic_info);
	compute_histograms(board_info);
	solve_hist_map(board_info);
	convert(basic_info, board_info);
	ft_putstrarr(basic_info->lines);
	return (0);
}
