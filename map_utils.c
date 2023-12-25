/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:40:16 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/15 03:24:30 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	row_count(char *str)
{
	int		i;
	char	**row_elems;
	char	**tmp;

	row_elems = ft_split(str, ' ');
	tmp = row_elems;
	i = 0;
	while (*tmp)
	{
		if (**tmp != '\n')
			i++;
		tmp++;
	}
	free_split(row_elems);
	return (i);
}

void	check_map_name(char *map_name)
{
	int		i;
	int		j;
	char	*match_str;

	match_str = ".fdf";
	i = 0;
	j = 0;
	while (map_name[i] != '.')
	{
		i++;
		if (map_name[i] == '.')
		{
			while (map_name[i] && (match_str[j] == map_name[i]))
			{
				j++;
				i++;
			}
			if (match_str[j] == '\0' && map_name[i] == '\0')
				return ;
		}
	}
	quit_program(INVALID_MAP_NAME);
}

/*
	Allocates memory for points in 1d array and 2d array.
*/
void	allocate_map(t_map *map)
{
	int	x;

	map->points_1d = (t_point *)malloc
		((sizeof(t_point) * (map->width) * (map->height)) + 1);
	if (!map->points_1d)
		exit(MEMORY_ERROR);
	map->tpoints_2d = (t_point **)malloc((sizeof(t_point *)
				* (map->width) + 1));
	if (!map->tpoints_2d)
		exit(MEMORY_ERROR);
	x = -1;
	while (++x < map->width)
		map->tpoints_2d[x] = (t_point *)malloc((sizeof(t_point)
					* (map->height)));
	if (!map->tpoints_2d)
		exit(MEMORY_ERROR);
}

void	init_map(t_map *map, char *map_name)
{
	map->width = 0;
	map->height = 0;
	map->size = 0;
	map->raw_arr = NULL;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	read_map_data(map, map_name);
	get_map_size(map);
	allocate_map(map);
}
