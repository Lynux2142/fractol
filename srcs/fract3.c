/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:14:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/16 10:56:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_const_var_3(t_shape *shape, t_draw *draw, t_fract *f)
{
	f->c_r = (double)draw->x / (shape->zoom) + shape->x1;
	f->c_i = (double)draw->y / (shape->zoom) + shape->y1;
	f->z_r = 0.0;
	f->z_i = 0.0;
	f->i = 0.0;
}

void			fract3(t_shape *shape)
{
	t_fract	f;

	ft_init(shape, &f.draw);
	while (++f.draw.x < shape->img_x)
	{
		f.draw.y = -1;
		while (++f.draw.y < shape->img_y)
		{
			ft_const_var_3(shape, &f.draw, &f);
			while (((f.z_r * f.z_r) + (f.z_i * f.z_i)) < 4.0
					&& f.i < shape->iter)
			{
				f.draw.tmp = (f.z_r * f.z_r) - (f.z_i * f.z_i) + f.c_r;
				f.z_i = 2.0 * fabs(f.z_r * f.z_i) + f.c_i;
				f.z_r = f.draw.tmp;
				f.i += 1.0;
			}
			if (f.i == shape->iter)
				fill_pixel(shape, f.draw.x, f.draw.y,
						(shape->color == 4) ? 0xFFFFFF : 0);
			else
				ft_set_color(shape, f);
		}
	}
}
