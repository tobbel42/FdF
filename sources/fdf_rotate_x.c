/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:36:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 17:48:36 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	x_rotate(t_point_3d *p, float rad)
{
	float	cosa;
	float	sina;

	cosa = cos(rad);
	sina = sin(rad);
	p->x = p->x;
	p->y = p->y * cosa - p->z * sina;
	p->z = p->y * sina + p->z * cosa;
}

void	fdf_rotate_x(t_fdf *fdf, int deg)
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
			x_rotate(fdf->matrix[y][x], rad);
			x++;
		}
		y++;
	}	
}
