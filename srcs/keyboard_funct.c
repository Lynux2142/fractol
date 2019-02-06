/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:30:34 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/05 16:56:35 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_move_fract(int key, t_shape *shape)
{
	if (key == U_ARROW)
	{
		shape->y1 -= (10.0 / shape->zoom);
		shape->y2 -= (10.0 / shape->zoom);
	}
	if (key == L_ARROW)
	{
		shape->x1 -= (10.0 / shape->zoom);
		shape->x2 -= (10.0 / shape->zoom);
	}
	if (key == D_ARROW)
	{
		shape->y1 += (10.0 / shape->zoom);
		shape->y2 += (10.0 / shape->zoom);
	}
	if (key == R_ARROW)
	{
		shape->x1 += (10.0 / shape->zoom);
		shape->x2 += (10.0 / shape->zoom);
	}
}

int			ft_key_funct(int key, t_shape *shape)
{
	if (key >= L_ARROW && key <= U_ARROW)
		ft_move_fract(key, shape);
	if (key == EQUAL)
		shape->iter += 10.0;
	if (key == MINUS)
		shape->iter -= 10.0;
	if (key == SPACE)
		ft_reset_fract(shape);
	if (key == ENTER)
		(shape->color < 1 || shape->color > 6) ?
		shape->color = 1 : ++shape->color;
	if (key == R_SHIFT)
		shape->ok = (shape->ok == 1) ? 0 : 1;
	if (key == ESC)
		exit(0);
	ft_display(shape);
	if (key == KEY_F)
	{
		ft_create_fdf(shape, shape->data);
		mlx_string_put(shape->mlx, shape->win, 340, 289, RED, "File Created");
	}
	ft_set_string(shape);
	if (key == KEY_H)
		ft_put_infos(shape);
	return (0);
}
