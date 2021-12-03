/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:36:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/11/30 11:38:57 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	x_rotate(t_point_3d *p, float rad)
{
	float	cosa;
	float	sina;
	float	pz;
	float	py;

	cosa = cos(rad);
	sina = sin(rad);
	py = p->y;
	pz = p->z;
	p->y = (py * cosa) - (pz * sina);
	p->z = (py * sina) + (pz * cosa);
}

/*
//rotates the matrix around the x axis by the given angle
*/
void	fdf_rotate_x(t_fdf *fdf)
{
	float	rad;
	int		x;
	int		y;

	rad = fdf->x_rot * M_PI / 180;
	y = 0;
	while (fdf->m[y])
	{
		x = 0;
		while (fdf->m[y][x])
		{
			x_rotate(fdf->m[y][x], rad);
			x++;
		}
		y++;
	}	
}
