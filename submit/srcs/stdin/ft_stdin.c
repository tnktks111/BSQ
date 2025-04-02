/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:16:35 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:05 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

char	*resize_buffer(char *input, long long *buf_size, long long i)
{
	char		*new_buf;
	long long	j;

	new_buf = (char *)malloc((*buf_size) * 2);
	if (!new_buf)
	{
		free(input);
		return (NULL);
	}
	j = 0;
	while (j < i)
	{
		new_buf[j] = input[j];
		j++;
	}
	free(input);
	*buf_size *= 2;
	return (new_buf);
}

int	get_input(char **input)
{
	long long	i;
	ssize_t		bytes_read;
	char		ch;
	long long	buf_size;

	i = 0;
	buf_size = BUF_SIZE;
	*input = (char *)malloc(buf_size);
	if (!*input)
		return (0);
	bytes_read = read(0, &ch, 1);
	while (bytes_read > 0)
	{
		if (ch == '\n' || ch == '\0')
			break ;
		if (i >= buf_size - 1)
		{
			*input = resize_buffer(*input, &buf_size, i);
			if (!*input)
				return (0);
		}
		(*input)[i++] = ch;
		bytes_read = read(0, &ch, 1);
	}
	(*input)[i] = '\0';
	return (1);
}
