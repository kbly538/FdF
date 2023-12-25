/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:45:20 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:10:41 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "fdf.h"

enum e_control_keys
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	SPACE = 49,
	ENTER = 36,
};

int	handle_exit(t_fdf *data);
int	handle_key_up(int keysym, t_fdf *data);
int	mouse_clicked(int button, int x, int y, t_fdf *fdf);
int	mouse_released(int button, int x, int y, t_fdf *fdf);
int	mouse_move(int x, int y, t_fdf *fdf);
int	handle_key_down(int keysym, t_fdf *fdf);
#endif