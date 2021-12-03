/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:33:20 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 11:04:36 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_x_rotate(t_point_3d *p, float rad)
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

void	fdf_y_rotate(t_point_3d *p, float rad)
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

void	fdf_z_rotate(t_point_3d *p, float rad)
{
	float	cosa;
	float	sina;
	float	px;
	float	py;

	cosa = cos(rad);
	sina = sin(rad);
	px = p->x;
	py = p->y;
	p->x = (px * cosa) - (py * sina);
	p->y = (px * sina) + (py * cosa);
}
