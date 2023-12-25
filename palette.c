/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:02:46 by kbilgili          #+#    #+#             */
/*   Updated: 2023/10/06 20:20:24 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*set_green_palette(void)
{
	int	*palette;

	palette = malloc(sizeof(int) * 10);
	if (!palette)
		quit_program(666);
	palette[0] = 0x003016;
	palette[1] = 0x00441d;
	palette[2] = 0x005923;
	palette[3] = 0x006f28;
	palette[4] = 0x00862b;
	palette[5] = 0x009d2d;
	palette[6] = 0x00b52d;
	palette[7] = 0x00cd2b;
	palette[8] = 0x00e625;
	palette[9] = 0x00ff18;
	return (palette);
}

int	*set_neon_palette(void)
{
	int	*palette;

	palette = malloc(sizeof(int) * 10);
	if (!palette)
		quit_program(666);
	palette[0] = 0xffffff;
	palette[1] = 0xefffff;
	palette[2] = 0xdfffff;
	palette[3] = 0xceffff;
	palette[4] = 0xbbffff;
	palette[5] = 0xa7feff;
	palette[6] = 0x91feff;
	palette[7] = 0x76fdff;
	palette[8] = 0x54fdff;
	palette[9] = 0x00fcff;
	return (palette);
}

int	*set_purple_palette(void)
{
	int	*palette;

	palette = malloc(sizeof(int) * 10);
	if (!palette)
		quit_program(666);
	palette[0] = 0x300000;
	palette[1] = 0x420013;
	palette[2] = 0x540022;
	palette[3] = 0x660036;
	palette[4] = 0x75004e;
	palette[5] = 0x7f006b;
	palette[6] = 0x83008c;
	palette[7] = 0x7d16b0;
	palette[8] = 0x6534d7;
	palette[9] = 0x004eff;
	return (palette);
}

int	*set_martian_palette(void)
{
	int	*palette;

	palette = malloc(sizeof(int) * 10);
	if (!palette)
		quit_program(666);
	palette[0] = 0xffaf04;
	palette[1] = 0xffa300;
	palette[2] = 0xff9700;
	palette[3] = 0xff8a00;
	palette[4] = 0xff7c00;
	palette[5] = 0xff6d00;
	palette[6] = 0xff5d00;
	palette[7] = 0xff4a00;
	palette[8] = 0xff3300;
	palette[9] = 0xff0000;
	return (palette);
}

void	init_palettes(t_fdf *fdf, int *palette_func(void))
{
	fdf->palette = palette_func();
}
