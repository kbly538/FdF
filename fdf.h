/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbilgili <kbilgili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:08:11 by kbilgili          #+#    #+#             */
/*   Updated: 2023/12/17 22:37:52 by kbilgili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "math.h"
# include "libft.h"
# include "mlx.h"
# include "errno.h"
# include "error.h"
# include "ft_printf.h"
# include "map.h"
# include "utils.h"
# include "camera.h"
# include "fcntl.h"
# include "palette.h"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FDF_BUFFER_SIZE 250000
# define INT_MIN -2147483648
# define INT_MAX 2147483647

enum	e_hook_keys
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_controller_state
{
	int	left_mouse_clicked;
	int	right_mouse_clicked;
	int	space_pressed;
}				t_controller_state;

typedef struct s_info_screen
{
	void	*image;
	int		bpp;
	int		line_bytes;
	int		endian;
	char	*img_buff;
	int		x_pos;
}				t_info_screen;

typedef struct s_fdf
{
	t_mlx				mlx;
	void				*image;
	int					bpp;
	int					line_bytes;
	int					endian;
	char				*img_buff;
	t_map				map;
	int					zoom;
	t_camera			camera;
	int					prev_x;
	int					prev_y;
	t_info_screen		*info_screen;
	int					renders;
	t_controller_state	controller_state;
	float				height_factor;
	int					auto_rotate;
	int					*palette;
}				t_fdf;

int		rgb_to_int(double r, double g, double b);
int		row_count(char *str);
void	load_map(t_map *map, char *map_name);
int		atoi_hex(char *hex_color);
int		render(t_fdf *fdf);
int		apply_camera(t_fdf *fdf, t_camera cam, t_point *p);
int		clean_kill(t_fdf *fdf);
int		setup_camera(t_fdf *fdf, t_camera *camera);
void	project_isometric(t_fdf *fdf, t_point *p);
void	project_parallel(t_fdf *fdf, t_point *p);
void	project_transformed(t_fdf *fdf, t_point *p);
void	rotate_x(t_fdf *fdf, t_point *p);
void	rotate_y(t_fdf *fdf, t_point *p);
void	rotate_z(t_fdf *fdf, t_point *p);
void	reset_angles(t_fdf *fdf);
void	set_color(t_fdf *fdf, t_map *map, t_point *p);
int		set_channel(int startcolor, int endcolor, float percent, int channel);
void	init_colors(t_fdf *fdf, t_map *map);
double	percent(int start, int end, int current);
int		get_color(t_point current, t_point start, t_point end, t_point delta);
void	init_palettes(t_fdf *fdf, int *paletter_func(void));
void	init_2d_map(t_fdf *fdf, t_map *map);
#endif
