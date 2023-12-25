/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_screen.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:51:06 by kbilgili          #+#    #+#             */
/*   Updated: 2023/10/06 02:14:14 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_SCREEN_H
# define INFO_SCREEN_H

# include "fdf.h"

# define INFO_SCREEN_WIDTH	350
# define INFO_SCREEN_HEIGHT WIN_HEIGHT

int		init_info_screen(t_fdf *fdf);
int		draw_info_screen(t_fdf *fdf);
void	write_render_info(t_fdf *fdf);
void	write_angle_info(t_fdf *fdf);
void	write_projection_info(t_fdf *fdf);
void	write_zoom_info(t_fdf *fdf);
void	write_z_info(t_fdf *fdf);
void	write_map_info(t_fdf *fdf);
void	write_height_info(t_fdf *fdf);
void	write_controller_info(t_fdf *fdf);

#endif