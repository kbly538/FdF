/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:43:25 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:29:34 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_screen.h"
#include "draw.h"
#include "fdf.h"

int	init_info_screen(t_fdf *fdf)
{
	fdf->info_screen = (t_info_screen *)malloc(sizeof(t_info_screen));
	if (!fdf->info_screen)
	{
		ft_printf("Couldn't initialize info screen.");
		exit(-1);
	}
	fdf->info_screen->image = mlx_new_image(fdf->mlx.mlx_ptr, 500, WIN_HEIGHT);
	fdf->info_screen->img_buff = mlx_get_data_addr(fdf->info_screen->image,
			&fdf->info_screen->bpp,
			&fdf->info_screen->line_bytes,
			&fdf->info_screen->endian);
	fdf->info_screen->x_pos = WIN_WIDTH - INFO_SCREEN_WIDTH;
	return (1);
}

void	write_to_info_screen(t_fdf *fdf)
{
	write_render_info(fdf);
	write_angle_info(fdf);
	write_projection_info(fdf);
	write_zoom_info(fdf);
	write_z_info(fdf);
	write_map_info(fdf);
	write_height_info(fdf);
	write_controller_info(fdf);
}

int	draw_info_screen(t_fdf *fdf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < INFO_SCREEN_WIDTH)
	{
		y = -1;
		while (++y < INFO_SCREEN_HEIGHT)
			put_pixel_on_img_extra(fdf, x, y, 0xAA202000);
	}
	write_to_info_screen(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr,
		fdf->info_screen->image, fdf->info_screen->x_pos, 0);
	return (1);
}
