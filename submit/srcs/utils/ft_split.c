/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:17:11 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:31 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

char	**ft_split(char *str, int row, int col)
{
	char	**words;
	int		i;
	int		j;

	words = (char **)malloc(sizeof(char *) * (row + 1));
	i = 0;
	while (*str != '\n')
		str++;
	str++;
	while (i < row)
	{
		words[i] = (char *)malloc(sizeof(char) * (col + 1));
		j = 0;
		while (j < col && *str != '\n' && *str != '\0')
			words[i][j++] = *str++;
		words[i][j] = '\0'; // 文字列の終端
		if (*str == '\n')
			str++;
		i++;
	}
	words[i] = NULL;
	return (words);
}
