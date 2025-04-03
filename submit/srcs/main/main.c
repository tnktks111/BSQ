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
	int			check;
	char		*input;

	i = 1;
	if (argc == 1)
	{
		check = get_input(&input);
		stdin_general(input, check);
		free(input);
	}
	else
	{
		while (i < argc)
		{
			general(argv[i], i, argc);
			i++;
		}
	}
	return (0);
}

void	general(char *argvi, int i, int n)
{
	t_basic_info	*basic_info;
	basic_info = (t_basic_info *)malloc(sizeof(t_basic_info));	
	if (parse(argvi, basic_info))
	{
		ft_putstr_error("map error\n");
		if (i < n - 1)
			write(2, "\n", 1);
	}
	else
	{
		ft_putstrarr(basic_info->lines);
		if (i < n - 1)
			write(1, "\n", 1);
		t_basic_info_free(basic_info);
	}
}

void	stdin_general(char *input, int check)
{
	t_basic_info	*basic_info;
	basic_info = (t_basic_info *)malloc(sizeof(t_basic_info));
	if (!check)
	{
		ft_putstr_error("map error\n");
		free(basic_info);
	}
	else if (parse_input(input, basic_info))
	{
		ft_putstr_error("map error\n");
		free(basic_info);
	}
	else
	{
		ft_putstrarr(basic_info->lines);
		t_basic_info_free(basic_info);
	}
}
