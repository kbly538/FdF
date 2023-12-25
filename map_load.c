/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:44:26 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 20:07:12 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_2d_map(t_fdf *fdf, t_map *map)
{
	int	x;
	int	y;
	int	j;

	y = -1;
	j = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			assign_values_1d_to_2d(map, x, y, ++j);
	}
	init_colors(fdf, map);
}

char	*read_map_file(int fd)
{
	char	*buffer;
	char	*tmp;
	char	*raw_map_arr;
	int		num_of_read_bytes;

	buffer = malloc(FDF_BUFFER_SIZE * sizeof(char));
	if (!buffer)
		quit_program(MEMORY_ERROR);
	raw_map_arr = ft_strdup("");
	num_of_read_bytes = FDF_BUFFER_SIZE;
	while (num_of_read_bytes == FDF_BUFFER_SIZE)
	{
		ft_bzero(buffer, FDF_BUFFER_SIZE);
		num_of_read_bytes = read(fd, buffer, FDF_BUFFER_SIZE);
		tmp = raw_map_arr;
		raw_map_arr = ft_strjoin(raw_map_arr, buffer);
		free(tmp);
	}
	free(buffer);
	return (raw_map_arr);
}

void	extract_point_data(t_map *map, char **nodes, int *i)
{
	char	**node_data;
	char	**tmp_node_data;
	t_point	p;

	while (*nodes)
	{
		node_data = ft_split(*nodes, ',');
		tmp_node_data = node_data;
		p.z = ft_atoi(*node_data);
		if (tmp_node_data[1] == NULL || ft_strlen(tmp_node_data[1]) == 0)
			p.color = 0x0;
		else
			p.color = atoi_hex(tmp_node_data[1]);
		map->points_1d[*i] = p;
		(*i)++;
		nodes++;
		free_split(node_data);
	}
}

/*
	Loops over each row and each node in that row and extracts points data
	i.e. height(z) value and color(if encoded)
*/
static void	extract_row_data(t_map *map, char **rows)
{
	int		i;
	char	**splitted_nodes;
	char	**tmp;

	i = 0;
	while (*rows)
	{
		splitted_nodes = ft_split(*rows, ' ');
		tmp = splitted_nodes;
		extract_point_data(map, tmp, &i);
		free_split(splitted_nodes);
		rows++;
	}
}

void	load_map(t_map *map, char *map_name)
{
	char	**splitted_rows;
	char	**tmp;

	check_map_name(map_name);
	init_map(map, map_name);
	splitted_rows = ft_split(map->raw_arr, '\n');
	tmp = splitted_rows;
	extract_row_data(map, tmp);
	free(map->raw_arr);
	free_split(splitted_rows);
}
