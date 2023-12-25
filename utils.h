/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:48:02 by kbilgili          #+#    #+#             */
/*   Updated: 2023/11/10 04:33:18 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_seperator(char c);
int		is_upper(char c);
int		is_lower(char c);
void	free_split(char **strs);
int		ft_min(int x, int y);
int		ft_max(int x, int y);
float	deg_to_rad(float deg);
float	rad_to_deg(float rad);
#endif
