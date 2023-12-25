/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:19:28 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:23:45 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"

void	quit_program(int error_code)
{
	if (error_code == ARGV_COUNT)
		ft_printf("%s", "Usage: ./fdf [path_to_map]");
	else if (error_code == INVALID_MAP_NAME)
		ft_printf("%s", "Invalid map name.");
	else if (error_code == COULDNT_INIT_MLX)
		ft_printf("%s", "Couldn't initialize MLX.");
	else if (error_code == COULDNT_CREATE_WINDOW)
		ft_printf("%s", "Couldn't create window.");
	else if (error_code == COULDNT_LOAD_MAP)
		ft_printf("%s", "Couldn't load map.");
	else if (error_code == MEMORY_ERROR)
		ft_printf("%s", "Memory error.");
	else if (error_code == INVALID_MAP)
		ft_printf("%s", "Invalid map.");
	else if (error_code == READ_ERROR)
		ft_printf("%s", "Couldn't open map. Perhaps there is no such map?");
	else
		ft_printf("Error code %d: %s", error_code, "An error occured.");
	exit(-1);
}
