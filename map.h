/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:45:13 by kbilgili          #+#    #+#             */
/*   Updated: 2023/11/10 04:10:36 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define X 0
# define Y 1
# define Z 2
# define W 3

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
	float	vector[3];
}				t_point;

typedef struct s_map
{
	int			width;
	int			height;
	int			size;
	char		*raw_arr;
	t_point		*points_1d;
	t_point		**tpoints_2d;
	int			z_max;
	int			z_min;
}				t_map;

void	get_map_size(t_map *map);
void	load_map(t_map *map, char *map_name);
void	init_map(t_map *map, char *map_name);
void	check_map_name(char *map_name);
void	read_map_data(t_map *map, char *map_name);
char	*read_map_file(int fd);
void	assign_values_1d_to_2d(t_map *map, int x, int y, int j);
#endif

