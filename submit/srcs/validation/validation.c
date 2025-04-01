/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:17:23 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:28 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

//正常動作で0,それ以外は1
int	validation(char *str, t_basic_info *info)
{
	int	row_count;
	int	num;
	int	i;

	if (!check_head(str))
		return (1);
	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	info->row = num;
	info->empty = str[i++];
	info->obstacle = str[i++];
	info->full = str[i++];
	if (str[i] != '\n')
		return (1);
	str = &str[i + 1]; // ヘッダ行のあとに移動
	info->col = check_size(str);
	row_count = 0;
	while (*str)
	{
		if (!check_row(str, info->empty, info->obstacle, info->col))
			return (1);
		str += info->col + 1; // +1 は '\n' をスキップするため
		row_count++;
	}
	return (row_count != info->row);
}

int	is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	check_head(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] < '0' || str[0] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i] || !str[i + 1] || !str[i + 2] || !str[i + 3])
		return (0);
	if (str[i] == str[i + 1] || str[i + 1] == str[i + 2] || str[i
		+ 2] == str[i])
		return (0);
	if (!(is_printable(str[i]) && is_printable(str[i + 1]) && is_printable(str[i
				+ 2])))
		return (0);
	if (str[i + 3] != '\n')
		return (0);
	return (1);
}

int	check_size(char *str)
{
	int	count;

	count = 0;
	while (*str && *str != '\n')
	{
		str++;
		count++;
	}
	return (count);
}

//\nを除く一列のサイズが返り値("abc\n" -> 3)
int	check_row(char *row, char empty, char obstacle, int size)
{
	int	i;

	i = 0;
	while (row[i] != '\n')
	{
		if (row[i] != empty && row[i] != obstacle)
			return (0);
		i++;
	}
	if (i != size)
		return (0);
	return (1);
}
