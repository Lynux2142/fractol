/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:17:48 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/10 14:18:26 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_shape *shape, t_draw *draw)
{
	shape->img_x = shape->win_x;
	shape->img_y = shape->win_y;
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(
			shape->img, &shape->bpp, &shape->sizeline, &shape->endian);
	draw->x = -1;
}

void	fill_pixel(t_shape *shape, int x, int y, int color)
{
	if ((y >= 0 && y <= shape->img_y)
	&& (x >= 0 && x <= shape->img_x))
	{
		if (shape->endian == 0 && shape->bpp == (8 * 4))
		{
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline))] =
				(char)color;
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline)) + 1] =
				(char)(color >> 8);
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline)) + 2] =
				(char)(color >> 16);
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline)) + 3] =
				(char)0;
		}
	}
}

int		ft_couleur(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | (blue));
}

void	ft_julia_set(t_shape *shape)
{
	shape->c_r = -0.8;
	shape->c_i = 0.156;
}

void	ft_set_values(t_shape *shape)
{
	if (ft_strequ(FRACT1, shape->name) || ft_strequ(FRACT4, shape->name))
	{
		shape->iter = 50.0;
		shape->x1 = -2.1;
		shape->x2 = 1.1;
		shape->y1 = -1.2;
		shape->y2 = 1.2;
	}
	else if (ft_strequ(FRACT2, shape->name))
	{
		shape->iter = 150.0;
		shape->x1 = -1.6;
		shape->x2 = 1.6;
		shape->y1 = -1.2;
		shape->y2 = 1.2;
		ft_julia_set(shape);
	}
	else if (ft_strequ(FRACT3, shape->name))
	{
		shape->iter = 50.0;
		shape->x1 = -2.0;
		shape->x2 = 1.2;
		shape->y1 = -1.7;
		shape->y2 = 0.7;
	}
}
