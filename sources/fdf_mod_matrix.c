/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mod_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:55:16 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 20:36:53 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//applies all the changes to the matrix copy
*/
void	fdf_mod_matrix(t_fdf *fdf)
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
	while (fdf->og_m[y])
	{
		x = 0;
		while (fdf->og_m[y][x])
		{
			fdf->m[y][x]->x = fdf->og_m[y][x]->x * fdf->spread;
			fdf->m[y][x]->y = fdf->og_m[y][x]->y * fdf->spread;
			fdf->m[y][x]->z = fdf->og_m[y][x]->z * fdf->spread;
			fdf_x_rotate(fdf->m[y][x], rx);
			fdf_y_rotate(fdf->m[y][x], ry);
			fdf_z_rotate(fdf->m[y][x], rz);
			fdf->m[y][x]->x += (float)fdf->x_trans * fdf->spread;
			fdf->m[y][x]->z += (float)fdf->y_trans * fdf->spread;
			x++;
		}
		y++;
	}
}
