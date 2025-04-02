/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:20:12 by ttanaka           #+#    #+#             */
/*   Updated: 2025/04/02 16:20:13 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

char	*get_sub(char *str, int left, int right)
{
	char	*sub;
	int		len;
	int		i;

	i = 0;
	len = right - left + 1;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = str[left + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
