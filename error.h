/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:21:25 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 23:23:50 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_error
{
	ARGV_COUNT = 1000,
	READ_ERROR = 1001,
	INVALID_MAP_NAME = 1002,
	COULDNT_INIT_MLX = 1004,
	COULDNT_CREATE_WINDOW = 1005,
	COULDNT_LOAD_MAP = 1006,
	MEMORY_ERROR = 1007,
	INVALID_MAP = 1008
};

void	quit_program(int error_code);
#endif
