/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 10:40:21 by lguiller          #+#    #+#             */
/*   Updated: 2018/07/25 13:56:39 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_const_var_4(t_shape *shape, t_draw *draw, t_fract *f)
{
	f->c_r = (double)draw->x / shape->zoom + shape->x1;
	f->c_i = (double)draw->y / shape->zoom + shape->y1;
	f->z_r = 0.0;
	f->z_i = 0.0;
	f->i = 0.0;
}

static void	ft_equation(t_fract *f, double iter)
{
	while (((f->z_r * f->z_r) + (f->z_i * f->z_i)) < 4.0
			&& f->i < iter)
	{
		f->draw.tmp = -f->z_r;
		f->z_r =
			(f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = 2.0 * f->z_i * f->draw.tmp + f->c_i;
		f->i += 1.0;
	}
}

void		*fract4(void *arg)
{
	int		i;
	t_shape	*shape;
	t_fract	f;

	i = -1;
	shape = arg;
	while (++i < THREAD)
	{
		f = shape->f;
		f.draw.y = -1.0;
		while (++f.draw.y < shape->img_y)
		{
			ft_const_var_4(shape, &f.draw, &f);
			ft_equation(&f, shape->iter);
			if (f.i == shape->iter)
				fill_pixel(shape, f.draw.x, f.draw.y,
						(shape->color == 4) ? 0xFFFFFF : 0);
			else
				ft_set_color(shape, f);
		}
		++shape->f.draw.x;
	}
	pthread_exit(NULL);
}
