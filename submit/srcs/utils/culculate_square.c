/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   culculate_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kueda <kueda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:16:47 by kueda             #+#    #+#             */
/*   Updated: 2025/04/01 20:46:08 by kueda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

int	calculate_square(int height, int width)
{
	int	small;

	small = ft_min(height, width);
	return (small * small);
}
