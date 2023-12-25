/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:36:47 by kbilgili          #+#    #+#             */
/*   Updated: 2023/10/06 03:12:54 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "info_screen.h"
#include "draw.h"

void	write_render_info(t_fdf *fdf)
{
	char	*num_of_renders;
	void	*mlx;
	void	*win;

	num_of_renders = ft_itoa(fdf->renders);
	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		5, RED, "RENDER INFO:");
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos,
		30, WHITE, "# of renders:");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos,
		30, GREEN, num_of_renders);
	free(num_of_renders);
}

void	write_angle_info(t_fdf *fdf)
{
	char	*alpha;	
	char	*beta;
	char	*gamma;
	void	*mlx;
	void	*win;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	alpha = ft_itoa(fdf->camera.alpha * 180 / M_PI);
	beta = ft_itoa(fdf->camera.beta * 180 / M_PI);
	gamma = ft_itoa(fdf->camera.gamma * 180 / M_PI);
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos, 55,
		WHITE, "[X, Y, Z]:");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos, 55, WHITE, "[");
	mlx_string_put(mlx, win, 180 + fdf->info_screen->x_pos, 55, GREEN, alpha);
	mlx_string_put(mlx, win, 210 + fdf->info_screen->x_pos, 55, WHITE, ", ");
	mlx_string_put(mlx, win, 230 + fdf->info_screen->x_pos, 55, GREEN, beta);
	mlx_string_put(mlx, win, 270 + fdf->info_screen->x_pos, 55, WHITE, ", ");
	mlx_string_put(mlx, win, 280 + fdf->info_screen->x_pos, 55, GREEN, gamma);
	mlx_string_put(mlx, win, 320 + fdf->info_screen->x_pos, 55, WHITE, "]");
	free(alpha);
	free(beta);
	free(gamma);
}

void	write_projection_info(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*projection;

	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	projection = "Not specified";
	mlx_string_put(mlx, win,
		5 + fdf->info_screen->x_pos, 80, WHITE, "Projection:");
	if (fdf->camera.projection == ISOMETRIC)
		projection = "Isometric";
	else if (fdf->camera.projection == PARALLEL)
		projection = "Parallel";
	else if (fdf->camera.projection == FREE)
		projection = "Free";
	else if (fdf->camera.projection == TOPDOWN)
		projection = "Bird's Eye";
	mlx_string_put(mlx, win,
		170 + fdf->info_screen->x_pos, 80, GREEN, projection);
}

void	write_zoom_info(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*zoom;

	zoom = ft_itoa(fdf->camera.zoom);
	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win, 5 + fdf->info_screen->x_pos, 105, WHITE, "Zoom:");
	mlx_string_put(mlx, win, 170 + fdf->info_screen->x_pos, 105, GREEN, zoom);
	mlx_string_put(mlx, win, 195 + fdf->info_screen->x_pos, 105, WHITE, "x");
	free(zoom);
}

void	write_z_info(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*height_factor;

	height_factor = ft_itoa((int)fdf->height_factor);
	mlx = fdf->mlx.mlx_ptr;
	win = fdf->mlx.win_ptr;
	mlx_string_put(mlx, win,
		5 + fdf->info_screen->x_pos, 130, 0Xffffff, "Height Multiplier:");
	mlx_string_put(mlx, win,
		190 + fdf->info_screen->x_pos, 130, GREEN, height_factor);
	free(height_factor);
}
