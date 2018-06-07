/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:51:42 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/20 15:37:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_put_keybord(t_shape *shape, int y)
{
	mlx_string_put(shape->mlx, shape->win, 30, (y = 180), RED, "Mooving:");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"Up arrow    : move up");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"Down arrow  : move down");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"Left arrow  : move left");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"Right arrow : move right");
	mlx_string_put(shape->mlx, shape->win, 30, y += 40, RED, "Iterations:");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"\"-\"         : decrease iterations");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"\"=\"         : increase iterations");
	mlx_string_put(shape->mlx, shape->win, 30, y += 40, RED, "Other:");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"Enter       : change color set");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"Right shift : lock/unlock variations");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"Space bar   : restore default");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"\"f\"         : generate .fdf");
	mlx_string_put(shape->mlx, shape->win, 50, y += 20, RED,
			"ESC         : Exit program");
}

void		ft_put_infos(t_shape *shape)
{
	t_rect	rect;
	int		x;
	int		y;

	rect.pos_x = 0;
	rect.pos_y = 0;
	rect.dim_x = shape->win_x;
	rect.dim_y = shape->win_y;
	rect.col = 0x33000000;
	put_rect(shape, &rect);
	mlx_string_put(shape->mlx, shape->win, (x = 310),
			(y = 40), RED, "SHORTCUTS SETTINGS");
	mlx_string_put(shape->mlx, shape->win, 145, y += 80, RED, "KEYBOARD");
	mlx_string_put(shape->mlx, shape->win, 595, y, RED, "MOUSE");
	mlx_string_put(shape->mlx, shape->win, 480, y += 60, RED, "Zoom:");
	mlx_string_put(shape->mlx, shape->win, 500, y += 20, RED,
			"MWHEELDOWN : zoom in");
	mlx_string_put(shape->mlx, shape->win, 500, y += 20, RED,
			"MWHEELUP   : zoom out");
	ft_put_keybord(shape, 180);
}
