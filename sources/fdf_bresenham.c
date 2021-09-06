/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:41:35 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 15:37:37 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	fdf_abs(int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	return (nbr);
}

static void	fast_x(t_b *b, t_point_2d *p1, t_fdf *fdf)
{
	int		x;
	int		y;
	float	err;
	int		col;

	col = 0x009800eb;
	err = (float)b->d[0] / 2.0;
	x = 0;
	y = 0;
	while (1)
	{
		mlx_pixel_put(fdf->ptr, fdf->win, p1->x + x + fdf->c->x,
			p1->y + y + fdf->c->y, col);
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
		mlx_pixel_put(fdf->ptr, fdf->win, p1->x + x + fdf->c->x,
			p1->y + y + fdf->c->y, col);
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
