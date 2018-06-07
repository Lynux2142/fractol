/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:08:29 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/16 10:48:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static int	ft_puthex_fd(unsigned char c, int fd)
{
	static char tab[] = "0123456789ABCFEF";

	ft_putchar_fd(tab[c / 16], fd);
	ft_putchar_fd(tab[c % 16], fd);
	return (1);
}

static void	ft_write_data(t_shape *shape, char *data, int fd)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while ((x += 4) < (shape->img_y * shape->sizeline))
	{
		i += 4;
		if (i >= shape->sizeline)
		{
			ft_putchar_fd('\n', fd);
			i = 0;
		}
		else
		{
			ft_putnbr_fd((((int)((t_uc)data[x] + (t_uc)data[x + 1] +
				(t_uc)data[x + 2]) / 3) * 100 / 255), fd);
			ft_putstr_fd(",0x", fd);
			ft_puthex_fd((unsigned char)data[x + 2], fd);
			ft_puthex_fd((unsigned char)data[x + 1], fd);
			ft_puthex_fd((unsigned char)data[x], fd);
			ft_putchar_fd(' ', fd);
		}
	}
}

void		ft_create_fdf(t_shape *shape, char *data)
{
	int		fd;

	(void)data;
	if ((fd = open("fract.fdf", O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR)) == -1)
	{
		perror("error");
		exit(5);
	}
	ft_write_data(shape, data, fd);
	if ((close(fd) == -1))
	{
		perror("error");
		exit(6);
	}
}
