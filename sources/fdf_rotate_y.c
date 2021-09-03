/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:47:49 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/03 15:10:17 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	y_rotate(t_point_3d *p, float rad)
{
	float	cosa;
	float	sina;

	cosa = cos(rad);
	sina = sin(rad);
	p->x = (p->x * cosa) + (p->z * sina);
	p->z = (-1 * p->x * sina) + (p->z * cosa);
}

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