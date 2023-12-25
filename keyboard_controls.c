/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:24:17 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:29:57 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "controller.h"
#include "draw.h"

int	handle_key_down(int keysym, t_fdf *fdf)
{
	if (keysym == SPACE)
		fdf->controller_state.space_pressed = 1;
	if (keysym == ENTER)
	{
		if (fdf->auto_rotate > 0)
			fdf->auto_rotate *= -1;
		else
			fdf->auto_rotate = 1;
	}
	return (1);
}

void	handle_projection_keys(int keysym, t_fdf *fdf)
{
	if (keysym == KEY_1)
		fdf->camera.projection = ISOMETRIC;
	if (keysym == KEY_2)
		fdf->camera.projection = PARALLEL;
	if (keysym == KEY_3)
	{
		reset_angles(fdf);
		fdf->camera.projection = FREE;
	}
	if (keysym == KEY_4)
		fdf->camera.projection = TOPDOWN;
}

void	handle_rotation_keys(int keysym, t_fdf *fdf)
{
	if (keysym == KEY_Z)
		fdf->height_factor += 0.1;
	if (keysym == KEY_X)
		fdf->height_factor -= 0.1;
	if (keysym == KEY_Q && fdf->camera.projection == FREE)
		fdf->camera.alpha -= 0.1;
	if (keysym == KEY_A && fdf->camera.projection == FREE)
		fdf->camera.alpha += 0.1;
	if (keysym == KEY_W && fdf->camera.projection == FREE)
		fdf->camera.beta -= 0.1;
	if (keysym == KEY_S && fdf->camera.projection == FREE)
		fdf->camera.beta += 0.1;
	if (keysym == KEY_E && fdf->camera.projection == FREE)
		fdf->camera.gamma -= 0.1;
	if (keysym == KEY_D && fdf->camera.projection == FREE)
		fdf->camera.gamma += 0.1;
}

int	handle_key_up(int keysym, t_fdf *fdf)
{
	handle_projection_keys(keysym, fdf);
	handle_rotation_keys(keysym, fdf);
	if (keysym == 53)
		clean_kill(fdf);
	fdf->controller_state.space_pressed = 0;
	update_scene(fdf);
	return (0);
}
