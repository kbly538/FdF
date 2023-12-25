/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:47:53 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/18 01:58:38 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **strs)
{
	char	**tmp;

	tmp = strs;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(strs);
}

int	clean_kill(t_fdf *fdf)
{
	t_point	**tpoint_row2;
	int		i;

	tpoint_row2 = fdf->map.tpoints_2d;
	i = 0;
	while (i < fdf->map.width)
	{
		free(tpoint_row2[i]);
		i++;
	}
	free(tpoint_row2);
	free(fdf->map.points_1d);
	mlx_destroy_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->image);
	free(fdf->info_screen);
	//system("leaks fdf");
	exit(0);
}
