/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:10:44 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/18 01:53:55 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "palette.h"

void	set_palette(t_point *p, float percent, int *palette)
{
	if (percent <= 0.1)
		p->color = palette[0];
	else if (percent <= 0.2)
		p->color = palette[1];
	else if (percent <= 0.3)
		p->color = palette[2];
	else if (percent <= 0.4)
		p->color = palette[3];
	else if (percent <= 0.5)
		p->color = palette[4];
	else if (percent <= 0.6)
		p->color = palette[5];
	else if (percent <= 0.7)
		p->color = palette[6];
	else if (percent <= 0.8)
		p->color = palette[7];
	else if (percent <= 0.9)
		p->color = palette[8];
	else if (percent <= 1.0)
		p->color = palette[9];
}

void	set_color(t_fdf *fdf, t_map *map, t_point *p)
{
	float	percent;

	if (map->z_max - map->z_min != 0)
		percent = p->z / (map->z_max - map->z_min);
	else
		percent = 0;
	set_palette(p, percent, fdf->palette);
}

int	set_channel(int startcolor, int endcolor, float percent, int channel)
{
	int	new_channel_value;
	int	shift_size;
	int	new_start_chan;
	int	new_end_chan;

	if (channel == 'R')
		shift_size = 16;
	else if (channel == 'G')
		shift_size = 8;
	else
		shift_size = 0;
	new_start_chan = startcolor >> shift_size & 0xFF;
	new_end_chan = (endcolor >> shift_size) & 0xFF;
	new_channel_value = (int)((1 - percent) * new_start_chan
			+ percent * new_end_chan);
	return (new_channel_value);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	delta.x = 12;
	if (current.color == end.color)
		return (current.color);
	//if (delta.x > delta.y)
		percentage = percent(start.vector[X], end.vector[X], current.vector[X]);
	// else
	// 	percentage = percent(start.vector[Y], end.vector[Y], current.vector[Y]);
	red = set_channel(start.color, end.color, percentage, 'R');
	green = set_channel(start.color, end.color, percentage, 'G');
	blue = set_channel(start.color, end.color, percentage, 'B');
	return ((red << 16) | (green << 8) | blue);
}
