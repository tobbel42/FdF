/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:47:49 by tgrossma          #+#    #+#             */
/*   Updated: 2021/11/30 11:39:57 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	y_rotate(t_point_3d *p, float rad)
{
	float	cosa;
	float	sina;
	float	px;
	float	pz;

	cosa = cos(rad);
	sina = sin(rad);
	px = p->x;
	pz = p->z;
	p->x = (px * cosa) + (pz * sina);
	p->z = (-1 * px * sina) + (pz * cosa);
}

/*
//rotates the matrix around the y axis by the given angle
*/
void	fdf_rotate_y(t_fdf *fdf)
{
	float	rad;
	int		x;
	int		y;

	rad = fdf->y_rot * M_PI / 180;
	y = 0;
	while (fdf->m[y])
	{
		x = 0;
		while (fdf->m[y][x])
		{
			y_rotate(fdf->m[y][x], rad);
			x++;
		}
		y++;
	}	
}
