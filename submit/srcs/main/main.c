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
	long long	i;
	char		*input;

	i = 1;
	if (argc == 1)
	{
		if (!get_input(&input))
		{
			ft_putstr_error("map error\n");
			return (1);
		}
		if (parse_input(input))
			ft_putstr_error("map error\n");
		free(input);
	}
	else
	{
		while (i < argc)
			if (parse(argv[i++]))
				ft_putstr_error("map error\n");
	}
	return (0);
}
