/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:04 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:28:58 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	process_map_data(t_map *map, int c, int *row_length)
{
	if (map->raw_arr[c] == '\n'
		&& map->raw_arr[c + 1] == '\0')
		return (0);
	if (ft_isalnum(map->raw_arr[c]) && is_seperator(map->raw_arr[c + 1]))
		(*row_length)++;
	if (map->raw_arr[c] == '\n')
	{
		map->height++;
		if (map->width != 0 && (map->width != *row_length))
			quit_program(INVALID_MAP);
		else
			map->width = *row_length;
		*row_length = 0;
	}
	return (1);
}

/*
Reads the bytes in the raw_arr and determines the dimensions of the map
*/
void	get_map_size(t_map *map)
{
	int	c;
	int	row_length;

	c = -1;
	row_length = 0;
	while (map->raw_arr[++c])
	{
		if (!process_map_data(map, c, &row_length))
			break ;
	}
	map->height++;
	if (map->height == 1)
		map->width = row_length;
	if ((map->width != row_length)) //TODO //&& map->height != 1
		quit_program(INVALID_MAP);
	map->size = map->width * map->height;
}

/*
Reads every single byte of data encoded in the file to the raw array in t_map
For example:
	"0,0x810202 1,0x810202\n
	5,0x810202 10,0x810202\n
*/
void	read_map_data(t_map *map, char *map_name)
{
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 2)
		quit_program(READ_ERROR);
	map->raw_arr = read_map_file(fd);
	close(fd);
}

void	assign_values_1d_to_2d(t_map *map, int x, int y, int j)
{
	map->tpoints_2d[x][y] = map->points_1d[j];
	map->tpoints_2d[x][y].x = x;
	map->tpoints_2d[x][y].y = y;
	map->tpoints_2d[x][y].z = map->points_1d[j].z;
	if (map->tpoints_2d[x][y].z > map->z_max)
		map->z_max = map->tpoints_2d[x][y].z;
	if (map->tpoints_2d[x][y].z < map->z_min)
		map->z_min = map->tpoints_2d[x][y].z;
	map->tpoints_2d[x][y].color = map->points_1d[j].color;
	map->tpoints_2d[x][y].vector[X] = x;
	map->tpoints_2d[x][y].vector[Y] = y;
	map->tpoints_2d[x][y].vector[Z] = map->points_1d[j].z;
}
