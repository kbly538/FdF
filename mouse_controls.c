/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:23:04 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:28:18 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "draw.h"

int	mouse_clicked(int button, int x, int y, t_fdf *fdf)
{
	if (button == 2)
		fdf->controller_state.right_mouse_clicked = 1;
	fdf->prev_x = x;
	fdf->prev_y = y;
	if (button == 4)
		fdf->camera.zoom += 1;
	if (button == 5)
		fdf->camera.zoom -= 1;
	update_scene(fdf);
	return (1);
}

int	mouse_released(int button, int x, int y, t_fdf *fdf)
{
	fdf->controller_state.right_mouse_clicked = 0;
	if (button == 4)
		fdf->camera.zoom += 1;
	if (button == 5)
		fdf->camera.zoom -= 1;
	update_scene(fdf);
	ft_printf("Mouse position | x: %d y: %d\n", x, y);
	return (1);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->controller_state.right_mouse_clicked == 1
		&& fdf->controller_state.space_pressed == 0)
	{
		fdf->camera.x_shift -= fdf->prev_x - x;
		fdf->camera.y_shift -= fdf->prev_y - y;
	}
	else if (fdf->controller_state.right_mouse_clicked == 1
		&& fdf->controller_state.space_pressed == 1)
	{
		fdf->camera.alpha -= (fdf->prev_y - y) * 0.005;
		fdf->camera.beta -= (fdf->prev_x - x) * 0.005;
	}
	draw(fdf);
	update_scene(fdf);
	fdf->prev_x = x;
	fdf->prev_y = y;
	return (1);
}
