/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:27:47 by kbilgili          #+#    #+#             */
/*   Updated: 2023/11/10 02:12:02 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0x000000;
	color |= (int)(r * 255) << 16;
	color |= (int)(g * 255) << 8;
	color |= (int)(b * 255);
	return (color);
}

int	atoi_hex(char *x_clr)
{
	char	*digit_set_lower;
	char	*digit_set_upper;
	int		result;
	int		i;

	x_clr += 2;
	digit_set_upper = "0123456789ABCDEF";
	digit_set_lower = "0123456789abcdef";
	result = 0;
	i = 0;
	while (*x_clr)
	{
		i = 0;
		if (ft_isalnum(*x_clr) && is_lower(*x_clr))
			while (digit_set_lower[i] != *x_clr)
				i++;
		else if (ft_isalnum(*x_clr) && is_upper(*x_clr))
			while (digit_set_upper[i] != *x_clr)
				i++;
		else
			break ;
		result += ((result * 15) + i);
		x_clr++;
	}
	return (result);
}

void	init_colors(t_fdf *fdf, t_map *map)
{
	int	x;
	int	y;

	init_palettes(fdf, set_martian_palette);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->tpoints_2d[x][y].color == 0x0)
				set_color(fdf, map, &map->tpoints_2d[x][y]);
		}
	}
	free(fdf->palette);
}
