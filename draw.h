/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:29:50 by kbilgili          #+#    #+#             */
/*   Updated: 2023/10/06 01:38:29 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fdf.h"

# define RED 0XFF0000
# define GREEN 0X00FF00
# define BLUE 0X0000FF
# define YELLOW 0X00FFFF
# define WHITE 0XFFFFFF

int		put_pixel_on_img(t_fdf *fdf, int x, int y, int color);
int		put_pixel_on_img_extra(t_fdf *fdf, int x, int y, int color);
void	draw(t_fdf *fdf);
void	update_scene(t_fdf *fdf);
#endif