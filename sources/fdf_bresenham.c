/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:41:35 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 21:09:14 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	fdf_abs(int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}

static void	my_pixel_put(t_fdf *fdf, int x, int y, unsigned int color)
{
	void	*dst;
	
	
	if (x < 0 || x >= fdf->width || y < 0 || y >= fdf->height)
		return ;
	dst = fdf->img_addr + ((y * (fdf->img_ll))+ (x * (fdf->img_bpp / 8)));
	*(unsigned int *)dst = color;
}

static void	fast_x(t_b *b, t_point_2d *p1, t_fdf *fdf)
{
	int				x;
	int				y;
	float			err;
	unsigned int	col;

	col = 0x009800eb;
	err = (float)b->d[0] / 2.0;
	x = 0;
	y = 0;
	while (1)
	{
		my_pixel_put(fdf, p1->x + x + fdf->width/2,
			p1->y + y + fdf->height/2, col);
		if (fdf_abs(x) == b->d[0])
			break ;
		if (err < 0)
		{
			err += (float)b->d[0];
			y += b->s[1];
		}
		err -= (float)b->d[1];
		x += b->s[0];
	}
}

static void	fast_y(t_b *b, t_point_2d *p1, t_fdf *fdf)
{
	int		x;
	int		y;
	float	err;
	int		col;

	col = 0x009800eb;
	err = (float)b->d[1] / 2.0;
	x = 0;
	y = 0;
	while (1)
	{
		my_pixel_put(fdf, p1->x + x + fdf->width/2,
			p1->y + y + fdf->height/2, col);
		if (fdf_abs(y) == b->d[1])
			break ;
		if (err < 0)
		{
			err += (float)b->d[1];
			x += b->s[0];
		}
		err -= (float)b->d[0];
		y += b->s[1];
	}
}

static t_b	*create_b(t_point_2d *p1, t_point_2d *p2)
{
	t_b		*new_b;

	new_b = (t_b *)malloc(sizeof(t_b));
	if (!new_b)
		return (NULL);
	new_b->d[0] = fdf_abs(p1->x - p2->x);
	new_b->d[1] = fdf_abs(p1->y - p2->y);
	if (p2->x - p1->x >= 0)
		new_b->s[0] = 1;
	else
		new_b->s[0] = -1;
	if (p2->y - p1->y >= 0)
		new_b->s[1] = 1;
	else
		new_b->s[1] = -1;
	return (new_b);
}

/*
//draws a line on the screen between point 1 and point 2
*/
void	fdf_bresenham(t_point_2d *p1, t_point_2d *p2, t_fdf *fdf)
{
	t_b	*b;

	b = create_b(p1, p2);
	
	if (b)
	{
		if (b->d[0] >= b->d[1])
			fast_x(b, p1, fdf);
		else
			fast_y(b, p1, fdf);
		free (b);
	}
}
