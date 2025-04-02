/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:17:14 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:30 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

char	*ft_strjoin(char *s1, char *s2, long long len2)
{
	long long	len1;
	char		*res;
	long long	i;
	long long	j;

	len1 = ft_strlen(s1);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	j = 0;
	while (j < len2)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}
