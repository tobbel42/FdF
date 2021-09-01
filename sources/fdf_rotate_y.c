/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:47:49 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 17:49:51 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	y_rotate(t_point_3d *p, float rad)
{
	float	cosa;
	float	sina;

	cosa = cos(rad);
	sina = sin(rad);
	p->x = p->x * cosa + p->z * sina;
	p->y = p->y;
	p->z = (-1) * (p->x * sina) + p->z * cosa;
}

void	fdf_rotate_y(t_fdf *fdf, int deg)
{
	float	rad;
	int		x;
	int		y;

	rad = (float)deg * M_PI / 180;
	y = 0;
	while (fdf->matrix[y])
	{
		x = 0;
		while (fdf->matrix[y][x])
		{
			y_rotate(fdf->matrix[y][x], rad);
			x++;
		}
		y++;
	}	
}