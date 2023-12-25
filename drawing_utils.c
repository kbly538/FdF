/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:49:41 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:12:25 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"
#include "camera.h"

int	put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	int	pixel;

	if (fdf->bpp != 32)
		color = mlx_get_color_value(fdf->mlx.mlx_ptr, color);
	pixel = (y * fdf->line_bytes) + (x * 4);
	if (fdf->endian == 1)
	{
		fdf->img_buff[pixel] = color >> 24;
		fdf->img_buff[pixel + 1] = (color >> 16) & 0xFF;
		fdf->img_buff[pixel + 2] = (color >> 8) & 0xFF;
		fdf->img_buff[pixel + 3] = color & 0xFF;
	}
	else if (fdf->endian == 0)
	{
		fdf->img_buff[pixel] = color & 0xFF;
		fdf->img_buff[pixel + 1] = (char)((color >> 8) & 0xFF);
		fdf->img_buff[pixel + 2] = (char)((color >> 16) & 0xFF);
		fdf->img_buff[pixel + 3] = (color >> 24);
	}
	return (1);
}

int	put_pixel_on_img_extra(t_fdf *fdf, int x, int y, int color)
{
	int	pixel;

	if (fdf->info_screen->bpp != 32)
		color = mlx_get_color_value(fdf->mlx.mlx_ptr, color);
	pixel = (y * fdf->info_screen->line_bytes) + (x * 4);
	if (fdf->info_screen->endian == 1)
	{
		fdf->info_screen->img_buff[pixel] = color >> 24;
		fdf->info_screen->img_buff[pixel + 1] = (color >> 16) & 0xFF;
		fdf->info_screen->img_buff[pixel + 2] = (color >> 8) & 0xFF;
		fdf->info_screen->img_buff[pixel + 3] = color & 0xFF;
	}
	else if (fdf->info_screen->endian == 0)
	{
		fdf->info_screen->img_buff[pixel] = color & 0xFF;
		fdf->info_screen->img_buff[pixel + 1] = (color >> 8) & 0xFF;
		fdf->info_screen->img_buff[pixel + 2] = (color >> 16) & 0xFF;
		fdf->info_screen->img_buff[pixel + 3] = (color >> 24);
	}
	return (1);
}

int	is_out_of_bounds(t_point start, t_point end)
{
	int	out_of_bounds;

	out_of_bounds = 0;
	if (end.vector[X] >= WIN_WIDTH - 1 || end.vector[Y] >= WIN_HEIGHT - 1
		|| end.vector[Y] < 0 || end.vector[X] < 0
		|| start.vector[X] >= WIN_WIDTH - 1
		|| start.vector[Y] >= WIN_HEIGHT - 1
		|| start.vector[Y] < 0 || start.vector[X] < 0)
		out_of_bounds = 1;
	return (out_of_bounds);
}

void	bresenham(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max;
	t_point	delta;
	t_point	curr;

	apply_camera(fdf, fdf->camera, &start);
	apply_camera(fdf, fdf->camera, &end);
	x_step = end.vector[X] - start.vector[X];
	y_step = end.vector[Y] - start.vector[Y];
	max = ft_max(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	delta.x = fabs(start.vector[X] - end.vector[X]);
	delta.y = fabs(start.vector[Y] - end.vector[Y]);
	curr = start;
	while ((int)(curr.vector[X] - end.vector[X])
		|| (int)(curr.vector[Y] - end.vector[Y]))
	{
		if (!is_out_of_bounds(curr, end))
			put_pixel_on_img(fdf, (int)curr.vector[X], (int)curr.vector[Y],
				get_color(curr, start, end, delta));
		curr.vector[X] += x_step;
		curr.vector[Y] += y_step;
	}
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->map.height)
	{
		x = -1;
		while (++x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				bresenham(fdf, fdf->map.tpoints_2d[x][y],
					fdf->map.tpoints_2d[x + 1][y]);
			if (y < fdf->map.height - 1)
				bresenham(fdf, fdf->map.tpoints_2d[x][y],
					fdf->map.tpoints_2d[x][y + 1]);
		}
	}
}
