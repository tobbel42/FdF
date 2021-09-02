/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:23:35 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:51:08 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	z_rotate(t_point_3d *p, float rad)
{
	float	cosa;
	float	sina;

	cosa = cos(rad);
	sina = sin(rad);
	p->x = p->x * cosa - (p->y * sina);
	p->z = p->x * sina + p->y * cosa;
}

void	fdf_rotate_z(t_fdf *fdf)
{
	float	rad;
	int		x;
	int		y;

	rad = fdf->z_rot * M_PI / 180.0f;
	y = 0;
	while (fdf->m[y])
	{
		x = 0;
		while (fdf->m[y][x])
		{
			z_rotate(fdf->m[y][x], rad);
			x++;
		}
		y++;
	}	
}