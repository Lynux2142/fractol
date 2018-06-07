/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:27:27 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/05 16:58:54 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# ifdef __linux__
#  define ESC			65307
#  define U_ARROW		65362
#  define D_ARROW		65364
#  define R_ARROW		65363
#  define L_ARROW		65361
#  define KEY_A			97
#  define KEY_D			100
#  define KEY_F			102
#  define KEY_H			104
#  define SPACE			32
#  define EQUAL			61
#  define MINUS			45
#  define ENTER			65293
#  define R_SHIFT		65506
#  define L_CLIC		1
#  define R_CLIC		3
#  define MID_CLIC		2
#  define MWHEELUP		4
#  define MWHEELDOWN	5
# else
#  define ESC			53
#  define U_ARROW		126
#  define D_ARROW		125
#  define R_ARROW		124
#  define L_ARROW		123
#  define KEY_A			0
#  define KEY_D			2
#  define KEY_F			3
#  define KEY_H			4
#  define SPACE			49
#  define EQUAL			24
#  define MINUS			27
#  define ENTER			36
#  define R_SHIFT		258
#  define L_CLIC		1
#  define R_CLIC		2
#  define MID_CLIC		3
#  define MWHEELUP		4
#  define MWHEELDOWN	5
# endif

# define FRACT1 "mandelbrot"
# define FRACT2 "julia"
# define FRACT3 "burningship"
# define FRACT4 "tricorn"

# define RED 0xFF0000

typedef unsigned char	t_uc;

typedef struct			s_string
{
	int					mand;
	int					julia;
	int					burn;
	int					tri;
}						t_string;

typedef struct			s_rect
{
	int					pos_x;
	int					pos_y;
	int					dim_x;
	int					dim_y;
	int					col;
}						t_rect;

typedef struct			s_draw
{
	int					x;
	int					y;
	double				tmp;
}						t_draw;

typedef struct			s_fract
{
	t_draw				draw;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				i;
}						t_fract;

typedef struct			s_shape
{
	char				*name;
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					sizeline;
	int					endian;
	char				*data;
	int					win_x;
	int					win_y;
	int					img_x;
	int					img_y;
	double				iter;
	double				zoom;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				c_r;
	double				c_i;
	int					in_out;
	int					color;
	int					ok;
	t_string			string;
}						t_shape;

typedef void			(*t_funct)(t_shape*);

void					ft_usage(void);
void					ft_display(t_shape *shape);
int						ft_key_funct(int key, t_shape *shape);
int						ft_mouse_funct(int mouse, int x, int y, t_shape *shape);
t_funct					get_f_funct(char *name_f);
void					apply_zoom(t_shape *shape, int x, int y,
							double zoom_factor);
void					ft_init(t_shape *shape, t_draw *draw);
void					fill_pixel(t_shape *shape, int x, int y, int color);
int						ft_couleur(int red, int green, int blue);
void					fract1(t_shape *shape);
void					fract2(t_shape *shape);
void					fract3(t_shape *shape);
void					fract4(t_shape *shape);
void					ft_set_values(t_shape *shape);
int						ft_var_julia(int x, int y, t_shape *shape);
void					ft_set_color(t_shape *shape, t_fract f);
void					ft_set_string(t_shape *shape);
void					ft_create_fdf(t_shape *shape, char *data);
void					ft_reset_fract(t_shape *shape);
void					ft_put_infos(t_shape *shape);
void					put_rect(t_shape *shape, t_rect *rect);

#endif
