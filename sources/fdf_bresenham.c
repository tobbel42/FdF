/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:41:35 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/27 16:00:13 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	fdf_abs(int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}

static int	fdf_sign(int nbr)
{
	if (nbr < 0)
		return (-1);
	return (1);
}

static void	fast_x(int d[2], int s[2], t_point *p1, t_fdf *fdf)
{
	int		x;
	int		y;
	float	err;

	err = (float)d[0] / 2.0;
	x = 0;
	y = 0;
	while (1)
	{
		mlx_pixel_put(fdf->ptr, fdf->win, p1->x + x, p1->y + y, 0x00345678);
		if (fdf_abs(x) == d[0])
			break ;
		if (err < 0)
		{
			err += (float)d[0];
			y += s[1];
		}
		err -= (float)d[1];
		x += s[0];
	}
}

static void	fast_y(int d[2], int s[2], t_point *p1, t_fdf *fdf)
{
	int		x;
	int		y;
	float	err;

	err = (float)d[1] / 2.0;
	x = 0;
	y = 0;
	while (1)
	{
		mlx_pixel_put(fdf->ptr, fdf->win, p1->x + x, p1->y + y, 0x00345678);
		if (fdf_abs(y) == d[1])
			break ;
		if (err < 0)
		{
			err += (float)d[1];
			x += s[0];
		}
		err -= (float)d[0];
		y += s[1];
	}
}

void	fdf_bresenham(t_point *p1, t_point *p2, t_fdf *fdf)
{
	int		d[2];
	int		s[2];

	d[0] = fdf_abs(p1->x - p2->x);
	d[1] = fdf_abs(p1->y - p2->y);
	s[0] = fdf_sign(p2->x - p1->x);
	s[1] = fdf_sign(p2->y - p1->y);
	if (d[0] >= d[1])
		fast_x(d, s, p1, fdf);
	else
		fast_y(d, s, p1, fdf);
}
