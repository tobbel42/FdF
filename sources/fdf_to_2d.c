/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_to_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:24:06 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 14:05:40 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//projects a 3d point onto a 2d screen and returns the 2d point
*/
t_point_2d	*fdf_to_2d(t_point_3d *p, t_fdf *fdf)
{
	t_point_2d	*new_p;
	float		new_x;
	float		new_y;
	float		z_fac;

	z_fac = fdf->z / (p->z + fdf->z);
	new_x = (fdf->x / 2) + ((p->x - (fdf->x / 2)) * z_fac);
	new_y = (fdf->y / 2) + ((p->y - (fdf->y / 2)) * z_fac);
	new_p = fdf_create_point_2d(new_x, new_y);
	return (new_p);
}
