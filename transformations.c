/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:53 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/18 01:09:14 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_fdf *fdf, t_point *p)
{
	float	gamma;
	float	new_x;
	float	new_y;
	float	new_z;

	gamma = fdf->camera.gamma;
	new_x = p->vector[X] * cosf(gamma) + p->vector[Y] * -sinf(gamma);
	new_y = p->vector[X] * sinf(gamma) + p->vector[Y] * cosf(gamma);
	new_z = p->vector[Z] * -fdf->height_factor;
	p->vector[X] = new_x;
	p->vector[Y] = new_y;
	p->vector[Z] = new_z;
}

void	rotate_y(t_fdf *fdf, t_point *p)
{
	float	beta;
	float	new_x;
	float	new_z;

	beta = fdf->camera.beta;
	new_x = p->vector[X] * cosf(beta) + p->vector[Z] * sinf(beta);
	new_z = p->vector[X] * -sinf(beta) + p->vector[Z] * cosf(beta);
	p->vector[X] = new_x;
	p->vector[Z] = new_z;
}

void	rotate_x(t_fdf *fdf, t_point *p)
{
	float	alpha;
	float	new_y;
	float	new_z;

	alpha = fdf->camera.alpha;
	new_y = p->vector[Y] * cosf(alpha) + p->vector[Z] * -sinf(alpha);
	new_z = p->vector[Y] * sinf(alpha) + p->vector[Z] * cosf(alpha);
	p->vector[Y] = new_y;
	p->vector[Z] = new_z;
}