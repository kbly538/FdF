/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 05:12:04 by kbilgili          #+#    #+#             */
/*   Updated: 2023/10/06 02:14:01 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "info_screen.h"
#include "draw.h"

void	write_map_info(t_fdf *fdf)
{
	char	*size;
	char	*width;
	char	*height;
	void	*mlx;
	void	*win;

	size = ft_itoa(fdf->map.size);
	width = ft_itoa(fdf->map.width);
	height = ft_itoa(fdf->map.height);
	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		155, RED, "MAP INFO:");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos, 180, WHITE, "Size:");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos, 180, GREEN, size);
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos, 205, WHITE, "Width:");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos,
		205, GREEN, width);
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		230, WHITE, "Height:");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos, 230, GREEN, height);
	free(size);
	free(width);
	free(height);
}

void	write_height_info(t_fdf *fdf)
{
	char	*zmin;
	char	*zmax;
	void	*mlx;
	void	*win;

	zmin = ft_itoa(fdf->map.z_min);
	zmax = ft_itoa(fdf->map.z_max);
	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		255, WHITE, "Min Height: ");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos,
		255, GREEN, zmin);
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		280, WHITE, "Max Height: ");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos,
		280, GREEN, zmax);
	free(zmax);
	free(zmin);
}
