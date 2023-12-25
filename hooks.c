/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:02:02 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/15 02:43:44 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"
#include "camera.h"
#include "info_screen.h"
#include "controller.h"

int	handle_exit(t_fdf *fdf)
{
	clean_kill(fdf);
	exit(0);
}

int	render(t_fdf *fdf)
{
	if (fdf->auto_rotate == 1)
	{
		fdf->camera.alpha += 0.01;
		fdf->camera.beta += 0.02;
		if (fdf->camera.alpha >= 2 * M_PI)
			fdf->camera.alpha /= 360;
		if (fdf->camera.beta >= 2 * M_PI)
			fdf->camera.beta /= 360;
	}
	update_scene(fdf);
	return (1);
}
