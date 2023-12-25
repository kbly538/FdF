/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:16:12 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/18 01:44:42 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_isometric(t_fdf *fdf, t_point *p)
{
	float	new_x;
	float	new_y;
	float	true_isometric_angle;

	true_isometric_angle = 45.0;
	new_x = (p->vector[X] - p->vector[Y])
		* cosf(deg_to_rad(true_isometric_angle));
	new_y = (p->vector[X] + p->vector[Y])
		* sinf(deg_to_rad(true_isometric_angle)) - p->vector[Z] * fdf->height_factor;
	p->vector[X] = new_x;
	p->vector[Y] = new_y;
	fdf->camera.alpha = deg_to_rad(true_isometric_angle);
	fdf->camera.beta = deg_to_rad(true_isometric_angle);
}

void	project_parallel(t_fdf *fdf, t_point *p)
{
	float	new_x;
	float	new_y;

	new_x = (p->vector[X] - p->vector[Y])
		* cosf(-5);
	new_y = (p->vector[X] + p->vector[Y])
		* sinf(0) - p->vector[Z] * fdf->height_factor;
	p->vector[X] = new_x;
	p->vector[Y] = new_y;
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
}

/*
	Rotates the map around the origin
*/
void	project_transformed(t_fdf *fdf, t_point *p)
{
	p->vector[X] -= (fdf->map.width / 2);
	p->vector[Y] -= (fdf->map.height / 2);
	rotate_z(fdf, p);
	rotate_y(fdf, p);
	rotate_x(fdf, p);
	p->vector[X] += (fdf->map.width / 2);
	p->vector[Y] += (fdf->map.height / 2);
}
