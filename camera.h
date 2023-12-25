/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:24:36 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 16:18:47 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

enum e_projection
{
	ISOMETRIC = 1,
	PARALLEL = 2,
	FREE = 3,
	TOPDOWN = 4
};

typedef struct s_camera
{
	int		zoom;
	int		projection;
	int		x_shift;
	int		y_shift;
	float	alpha;
	float	beta;
	float	gamma;
}			t_camera;

#endif