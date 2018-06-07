/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:29:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/20 14:57:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_reset_fract(t_shape *shape)
{
	shape->zoom = 250.0;
	ft_set_values(shape);
	ft_set_string(shape);
}

void		ft_display(t_shape *shape)
{
	t_funct draw_f;

	draw_f = get_f_funct(shape->name);
	draw_f(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
}

static void	ft_init_values(t_shape *shape)
{
	shape->win_x = 800;
	shape->win_y = 600;
	shape->zoom = 250.0;
	shape->color = 1;
	shape->c_r = -0.8;
	shape->c_i = 0.156;
	shape->string.mand = RED;
	shape->string.julia = RED;
	shape->string.burn = RED;
	shape->string.tri = RED;
}

int			main(int ac, char **av)
{
	t_shape		shape;
	t_funct		draw_f;

	if (ac != 2 || get_f_funct(av[1]) == NULL)
		ft_usage();
	shape.name = av[1];
	ft_set_values(&shape);
	ft_init_values(&shape);
	shape.mlx = mlx_init();
	shape.win = mlx_new_window(shape.mlx, shape.win_x, shape.win_y, "fractol");
	draw_f = get_f_funct(av[1]);
	draw_f(&shape);
	mlx_put_image_to_window(shape.mlx, shape.win, shape.img, 0, 0);
	mlx_hook(shape.win, 2, (1L << 0), ft_key_funct, &shape);
	mlx_hook(shape.win, 6, (1L << 6), ft_var_julia, &shape);
	mlx_mouse_hook(shape.win, ft_mouse_funct, &shape);
	ft_set_string(&shape);
	mlx_loop(shape.mlx);
	return (0);
}
