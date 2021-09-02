/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:47:00 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:49:03 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	iso_transform(t_point_3d *p)
{
	p->x = (1 / sqrt(6)) * (p->x * sqrt(3) + p->z * sqrt(3));
	p->y = (1 / sqrt(6)) * (p->x + 2 * p->y + p->z);
	p->z = (1 / sqrt(6)) * (p->x * sqrt(2) - p->y * sqrt(2) + p->z * sqrt(2));
}

void	fdf_isometric(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (fdf->m[y])
	{
		x = 0;
		while (fdf->m[y][x])
		{
			iso_transform(fdf->m[y][x]);
			x++;
		}
		y++;
	}	
}
