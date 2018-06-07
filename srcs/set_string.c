/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:40:15 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/20 15:04:36 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_rect(t_shape *shape, t_rect *rect)
{
	int x;
	int y;

	x = rect->pos_x;
	while (x <= (rect->pos_x + rect->dim_x))
	{
		y = rect->pos_y;
		while (y <= (rect->pos_y + rect->dim_y))
		{
			mlx_pixel_put(shape->mlx, shape->win, x, y, rect->col);
			++y;
		}
		++x;
	}
}

static void	ft_change_string(t_shape *shape, t_rect *rect, int pos_y)
{
	rect->pos_y = pos_y;
	put_rect(shape, rect);
}

void		ft_set_string(t_shape *shape)
{
	t_rect	rect;

	rect.pos_x = 5;
	rect.dim_x = 120;
	rect.dim_y = 25;
	rect.col = RED;
	if (shape->string.mand == 0)
		ft_change_string(shape, &rect, 10);
	if (shape->string.julia == 0)
		ft_change_string(shape, &rect, 40);
	if (shape->string.burn == 0)
		ft_change_string(shape, &rect, 70);
	if (shape->string.tri == 0)
		ft_change_string(shape, &rect, 100);
	mlx_string_put(shape->mlx, shape->win, 10, 10,
			shape->string.mand, "Mandelbrot");
	mlx_string_put(shape->mlx, shape->win, 10, 40,
			shape->string.julia, "Julia");
	mlx_string_put(shape->mlx, shape->win, 10, 70,
			shape->string.burn, "BurningShip");
	mlx_string_put(shape->mlx, shape->win, 10, 100,
			shape->string.tri, "Tricorn");
	mlx_string_put(shape->mlx, shape->win, 690, 570, RED, "\"h\" : Help");
}
