/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:33:20 by tgrossma          #+#    #+#             */
/*   Updated: 2021/11/30 13:57:17 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate(t_point_3d *p, float rx, float ry, float rz)
{
	float	cosa[3];
	float	sina[3];
	float	px;
	float	pz;
	float	py;

	sina[0] = sin(rx);
	sina[1] = sin(ry);
	sina[2] = sin(rz);
	cosa[0] = cos(rx);
	cosa[1] = cos(ry);
	cosa[2] = cos(rz);
	px = p->x;
	py = p->y;
	pz = p->z;
	p->x = (((px * cosa[1]) + (((py * sina[0])
						+ (pz * cosa[0])) * sina[1])) * cosa[2])
		- ((py * cosa[0]) - (pz * sina[0]) * sina[2]);
	p->y = (((px * cosa[1]) + (((py * sina[0])
						+ (pz * cosa[0])) * sina[1])) * sina[2])
		+ (((py * cosa[0]) - (pz * sina[0])) * cosa[2]);
	p->z = (-1 * px * sina[1]) + (((py * sina[0])
				+ (pz * cosa[0])) * cosa[1]);
}

void	fdf_rotate(t_fdf *fdf)
{
	int		x;
	int		y;
	float	rx;
	float	ry;
	float	rz;

	rx = fdf->x_rot * M_PI / 180;
	ry = fdf->y_rot * M_PI / 180;
	rz = fdf->z_rot * M_PI / 180;
	y = 0;
	while (fdf->og_matrix[y])
	{
		x = 0;
		while (fdf->og_matrix[y][x])
		{
			rotate(fdf->m[y][x], rx, ry, rz);
			x++;
		}
		y++;
	}
}
