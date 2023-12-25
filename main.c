/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:07:47 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/18 01:58:28 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"
#include "info_screen.h"
#include "controller.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx.mlx_ptr = mlx_init();
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "FdF - kbilgili");
	fdf->image = mlx_new_image(fdf->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->img_buff = mlx_get_data_addr(fdf->image, &fdf->bpp,
			&fdf->line_bytes, &fdf->endian);
	init_2d_map(fdf, &fdf->map);
	setup_camera(fdf, &fdf->camera);
	init_info_screen(fdf);
	fdf->renders = 0;
	fdf->height_factor = 0.1;
	fdf->auto_rotate = 0;
	init_palettes(fdf, &set_martian_palette);
	fdf->controller_state.right_mouse_clicked = 0;
	fdf->controller_state.space_pressed = 0;
}

int	main(int count, char **argv)
{
	t_fdf	fdf;

	if (count != 2)
		quit_program(ARGV_COUNT);
	load_map(&fdf.map, argv[1]);
	init_fdf(&fdf);
	mlx_hook(fdf.mlx.win_ptr, ON_KEYUP, 0, handle_key_up, &fdf);
	mlx_hook(fdf.mlx.win_ptr, ON_KEYDOWN, 0, handle_key_down, &fdf);
	mlx_hook(fdf.mlx.win_ptr, ON_DESTROY, 0, handle_exit, &fdf);
	mlx_hook(fdf.mlx.win_ptr, ON_MOUSEDOWN, 0, mouse_clicked, &fdf);
	mlx_hook(fdf.mlx.win_ptr, ON_MOUSEUP, 0, mouse_released, &fdf);
	mlx_hook(fdf.mlx.win_ptr, ON_MOUSEMOVE, 0, mouse_move, &fdf);
	mlx_loop_hook(fdf.mlx.mlx_ptr, render, &fdf);
	update_scene(&fdf); 
	mlx_loop(fdf.mlx.mlx_ptr);
}
