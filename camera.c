/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:26:20 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:31:19 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_angles(t_fdf *fdf)
{
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
}

int	setup_camera(t_fdf *fdf, t_camera *camera)
{
	int	variable_zoom;
	int	map_size;

	map_size = fdf->map.size;
	//TODO başka yere taşı
	if (map_size > 15000)
		variable_zoom = 2;
	else if (map_size >= 10000)
		variable_zoom = 3;
	else if (map_size >= 2500)
		variable_zoom = 10;
	else
		variable_zoom = 20;
	camera->projection = ISOMETRIC;
	camera->zoom = variable_zoom;
	camera->x_shift = (WIN_WIDTH - fdf->map.width * camera->zoom) / 2;
	camera->y_shift = (WIN_HEIGHT - (fdf->map.height + ((fdf->map.width / fdf->map.height)
		* fdf->map.height)) * camera->zoom) / 2;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	return (1);
}

int	apply_camera(t_fdf *fdf, t_camera cam, t_point *p)
{
	p->vector[X] = p->x;
	p->vector[Y] = p->y;
	p->vector[Z] = p->z;
	if (cam.projection == ISOMETRIC)
		project_isometric(fdf, p);
	else if (cam.projection == PARALLEL)
		project_parallel(fdf, p);
	else if (cam.projection == FREE)
		project_transformed(fdf, p);
	p->vector[X] *= cam.zoom;
	p->vector[Y] *= cam.zoom;
	p->vector[X] += cam.x_shift;
	p->vector[Y] += cam.y_shift;
	return (1);
}
