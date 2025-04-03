/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:26:44 by ttanaka           #+#    #+#             */
/*   Updated: 2025/04/03 11:26:46 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

void	strarr_free(char **str)
{
	long long	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

void	longlong_tab_free(long long **tab, long long size)
{
	long long	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

void	t_basic_info_free(t_basic_info *t_basic_info)
{
	strarr_free(t_basic_info->lines);
	free(t_basic_info);
}

void	t_g_info_free(t_g_info *t_g_info)
{
	longlong_tab_free(t_g_info->grid, t_g_info->r);
	free(t_g_info);
}

void	t_g_info_replace(t_g_info *t_g_info, long long **newgrid)
{
	longlong_tab_free(t_g_info->grid, t_g_info->r);
	t_g_info->grid = newgrid;
}
