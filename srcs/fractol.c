/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:29:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/07/25 19:38:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_reset_fract(t_shape *shape)
{
	shape->zoom = 250.0;
	ft_set_values(shape);
	ft_set_string(shape);
}

static void	ft_cpy_struct(t_shape *tmp, t_shape *shape)
{
	tmp->name = shape->name;
	tmp->mlx = shape->mlx;
	tmp->win = shape->win;
	tmp->img = shape->img;
	tmp->bpp = shape->bpp;
	tmp->sizeline = shape->sizeline;
	tmp->endian = shape->endian;
	tmp->data = shape->data;
	tmp->win_x = shape->win_x;
	tmp->win_y = shape->win_y;
	tmp->img_x = shape->img_x;
	tmp->img_y = shape->img_y;
	tmp->iter = shape->iter;
	tmp->zoom = shape->zoom;
	tmp->x1 = shape->x1;
	tmp->x2 = shape->x2;
	tmp->y1 = shape->y1;
	tmp->y2 = shape->y2;
	tmp->c_r = shape->c_r;
	tmp->c_i = shape->c_i;
	tmp->in_out = shape->in_out;
	tmp->color = shape->color;
	tmp->ok = shape->ok;
	tmp->string = shape->string;
	tmp->f = shape->f;
}

void		ft_display(t_shape *shape)
{
	pthread_t	test[WINX / THREAD];
	t_shape		*tmp[WINX / THREAD];
	t_funct		draw_f;
	int			i;

	draw_f = get_f_funct(shape->name);
	ft_init(shape, &shape->f.draw);
	i = -1;
	while ((shape->f.draw.x += THREAD) < shape->img_x)
	{
		tmp[++i] = (t_shape*)malloc(sizeof(t_shape));
		ft_cpy_struct(tmp[i], shape);
		pthread_create(&test[i], NULL, draw_f, tmp[i]);
	}
	i = -1;
	while (++i < WINX / THREAD)
		pthread_join(test[i], NULL);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
}

static void	ft_init_values(t_shape *shape)
{
	shape->win_x = WINX;
	shape->win_y = WINY;
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

	if (ac != 2 || get_f_funct(av[1]) == NULL)
		ft_usage();
	shape.name = av[1];
	ft_set_values(&shape);
	ft_init_values(&shape);
	shape.mlx = mlx_init();
	shape.win = mlx_new_window(shape.mlx, shape.win_x, shape.win_y, "fractol");
	ft_display(&shape);
	mlx_put_image_to_window(shape.mlx, shape.win, shape.img, 0, 0);
	mlx_hook(shape.win, 2, (1L << 0), ft_key_funct, &shape);
	mlx_hook(shape.win, 6, (1L << 6), ft_var_julia, &shape);
	mlx_mouse_hook(shape.win, ft_mouse_funct, &shape);
	ft_set_string(&shape);
	mlx_loop(shape.mlx);
	return (0);
}
