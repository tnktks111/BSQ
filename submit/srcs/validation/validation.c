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
	long long	r_count;
	long long	num;

	if (!check_head(str))
		return (1);
	num = 0;
	str += ft_atoi(str, &num);
	info->r = num;
	info->empty = *str++;
	info->obstacle = *str++;
	info->full = *str++;
	if (*str++ != '\n')
		return (1);
	info->c = check_size(str);
	if (!info->c)
		return (1);
	r_count = 0;
	while (*str)
	{
		if (!check_r(str, info->empty, info->obstacle, info->c))
			return (1);
		str += info->c + 1;
		r_count++;
	}
	return (r_count != info->r);
}

int	is_print(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	check_head(char *str)
{
	long long	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] < '0' || str[0] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i] || !str[i + 1] || !str[i + 2] || !str[i + 3])
		return (0);
	if (str[i] == str[i +1] || str[i +1] == str[i +2] || str[i +2] == str[i])
		return (0);
	if (!(is_print(str[i]) && is_print(str[i +1]) && is_print(str[i +2])))
		return (0);
	if (str[i + 3] != '\n')
		return (0);
	return (1);
}

long long	check_size(char *str)
{
	long long	count;

	count = 0;
	while (*str && *str != '\n')
	{
		str++;
		count++;
	}
	return (count);
}

int	check_r(char *r, char empty, char obstacle, long long size)
{
	long long	i;

	i = 0;
	while (r[i] != '\n')
	{
		if (r[i] != empty && r[i] != obstacle)
			return (0);
		i++;
	}
	if (i != size)
		return (0);
	return (1);
}
