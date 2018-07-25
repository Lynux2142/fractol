/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/07/25 13:52:25 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_const_var_2(t_shape *shape, t_draw *draw, t_fract *f)
{
	f->c_r = shape->c_r;
	f->c_i = shape->c_i;
	f->z_r = (double)draw->x / (shape->zoom) + shape->x1;
	f->z_i = (double)draw->y / (shape->zoom) + shape->y1;
	f->i = 0.0;
}

static void	ft_equation(t_fract *f, double iter)
{
	while (((f->z_r * f->z_r) + (f->z_i * f->z_i)) < 4.0
			&& f->i < iter)
	{
		f->draw.tmp = f->z_r;
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = 2.0 * f->z_i * f->draw.tmp + f->c_i;
		f->i += 1.0;
	}
}

void		*fract2(void *arg)
{
	int		i;
	t_shape	*shape;
	t_fract	f;

	shape = arg;
	i = -1;
	while (++i < THREAD)
	{
		f = shape->f;
		f.draw.y = -1;
		while (++f.draw.y < shape->img_y)
		{
			ft_const_var_2(shape, &f.draw, &f);
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
