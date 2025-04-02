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

int	handle_buffer_resize(char **buffer, long long *buf_size, long long i)
{
	*buffer = resize_buffer(*buffer, buf_size, i);
	if (!*buffer)
		return (0);
	return (1);
}

int	get_input(char **input)
{
	long long	i;
	ssize_t		bytes_read;
	long long	buf_size;
	char		*buffer;

	i = 0;
	buf_size = BUF_SIZE;
	buffer = (char *)malloc(buf_size);
	if (!buffer)
		return (0);
	bytes_read = read(0, buffer + i, buf_size - i - 1);
	while (bytes_read > 0)
	{
		i += bytes_read;
		if (i >= buf_size - 1)
			if (!handle_buffer_resize(&buffer, &buf_size, i))
				return (0);
		bytes_read = read(0, buffer + i, buf_size - i - 1);
	}
	if (i == 0)
		return (free(buffer), 0);
	buffer[i] = '\0';
	*input = buffer;
	return (1);
}
