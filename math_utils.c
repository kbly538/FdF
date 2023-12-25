/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:35:27 by kbilgili          #+#    #+#             */
/*   Updated: 2023/10/06 01:32:35 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	ft_min(int x, int y)
{
	if (y > x)
		return (x);
	else
		return (y);
}

float	deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

float	rad_to_deg(float rad)
{
	return (rad * 180 / M_PI);
}
