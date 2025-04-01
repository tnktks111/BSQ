/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:15:55 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:45:55 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

int	main(int argc, char *argv[])
{
	int		i;
	char	input[BUF_SIZE];

	i = 1;
	if (argc == 1)
	{
		get_input(input);
		if (parse(input))
			ft_putstr_error("map error\n");
	}
	if (argc > 1)
	{
		while (i < argc)
			if (parse(argv[i++]))
				ft_putstr_error("map error\n");
	}
	return (0);
}
