/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_project_cam.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:23:02 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/03 13:22:19 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point_2d	*fdf_project_cam(t_point_3d *p, t_fdf *fdf)
{
	t_point_2d	*new_p;
	float		fac;
	int			x;
	int			y;

	fac = (fdf->cam->z / (p->z +fdf->cam->z));
	x = rint((p->x - fdf->cam->x) * fac + fdf->cam->x);
	y = rint((p->y - fdf->cam->y) * fac + fdf->cam->y);
	new_p = fdf_create_point_2d(x, y);
	return (new_p);
}
