/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:57:32 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:28:11 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "info_screen.h"
#include "draw.h"

//TODO
void	clear_display(t_fdf *fdf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
			put_pixel_on_img(fdf, x, y, 0X0);
	}
}

void	update_scene(t_fdf *fdf)
{
	fdf->renders++;
	clear_display(fdf);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr,
		fdf->mlx.win_ptr, fdf->image, 0, 0);
	draw_info_screen(fdf);
}
