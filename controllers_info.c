/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 02:11:03 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:35:11 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"

void	write_projection_controllers(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		565, WHITE, "Change Projection:");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		585, GREEN, "Isometric: ");
	mlx_string_put(mlx, win, 135 + fdf->info_screen->x_pos,
		585, GREEN, "[1]");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		605, GREEN, "Parallel: ");
	mlx_string_put(mlx, win, 135 + fdf->info_screen->x_pos,
		605, GREEN, "[2] - (Side View)");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		625, GREEN, "Free Rotate: ");
	mlx_string_put(mlx, win, 135 + fdf->info_screen->x_pos,
		625, GREEN, "[3]");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		645, GREEN, "Bird's Eye: ");
	mlx_string_put(mlx, win, 135 + fdf->info_screen->x_pos,
		645, GREEN, "[4]");
}

void	write_axes_controllers_complement(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		465, GREEN, "Incrs:");
	mlx_string_put(mlx, win, 75 + fdf->info_screen->x_pos,
		465, RED, "A ");
	mlx_string_put(mlx, win, 95 + fdf->info_screen->x_pos,
		465, GREEN, "S ");
	mlx_string_put(mlx, win, 115 + fdf->info_screen->x_pos,
		465, BLUE, "D");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		485, GREEN, "Decrs: ");
	mlx_string_put(mlx, win, 75 + fdf->info_screen->x_pos,
		485, RED, "Q ");
	mlx_string_put(mlx, win, 95 + fdf->info_screen->x_pos,
		485, GREEN, "W ");
	mlx_string_put(mlx, win, 115 + fdf->info_screen->x_pos,
		485, BLUE, "E");
}

void	write_axes_controllers(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		445, WHITE, "Rotate ");
	mlx_string_put(mlx, win, 75 + fdf->info_screen->x_pos,
		445, RED, "X ");
	mlx_string_put(mlx, win, 95 + fdf->info_screen->x_pos,
		445, GREEN, "Y ");
	mlx_string_put(mlx, win, 115 + fdf->info_screen->x_pos,
		445, BLUE, "Z");
	mlx_string_put(mlx, win, 135 + fdf->info_screen->x_pos,
		445, WHITE, "axes: (Free Prj.) ");
	write_axes_controllers_complement(fdf);
}

void	write_map_controllers(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		345, WHITE, "Move mesh:");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		365, GREEN, "Hold [RMB] & Move");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		395, WHITE, "Rotate mesh: (Free Projection)");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		415, GREEN, "Hold [Space + RMB] & Move");
	write_axes_controllers(fdf);
}

void	write_controller_info(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		320, RED, "CONTROLLERS:");
	write_map_controllers(fdf);
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		515, WHITE, "Modify height:");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		535, GREEN, "Increase [Z] - Decrease [X]");
	write_projection_controllers(fdf);
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		675, WHITE, "Auto Rotate: ");
	if (fdf->auto_rotate == 1)
		mlx_string_put(mlx, win, 135 + fdf->info_screen->x_pos,
			675, GREEN, "[Enter] on");
	else
		mlx_string_put(mlx, win, 135 + fdf->info_screen->x_pos,
			675, GREEN, "[Enter] off");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		705, WHITE, "Quit: ");
	mlx_string_put(mlx, win, 65 + fdf->info_screen->x_pos,
		705, GREEN, "[ESC]");
}
