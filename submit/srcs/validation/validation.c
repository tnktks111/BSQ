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
	str += ft_atoi(str, &num, check_size(str) - 4);
	info->r = num;
	set_info(info, str[0], str[1], str[2]);
	str += 4;
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

void	set_info(t_basic_info *info, char e, char o, char f)
{
	info->empty = e;
	info->obstacle = o;
	info->full = f;
}

int	check_head(char *s)
{
	long long	j;
	char		*num;

	j = check_size(s);
	if (j < 4)
		return (0);
	if (s[j -1] == s[j -2] || s[j -2] == s[j -3] || s[j -3] == s[j -1])
		return (0);
	if (!(is_print(s[j - 1]) && is_print(s[j - 2]) && is_print(s[j - 3])))
		return (0);
	num = get_sub(s, 0, j - 4);
	if (!(ft_is_numeric(num)))
		return (free(num), 0);
	return (free(num), 1);
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
