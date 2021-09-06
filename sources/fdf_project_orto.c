/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_project_orto.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:08:40 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:45:07 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//projects a 3d point onto a 2d plane
*/
t_point_2d	*fdf_project_orto(t_point_3d *p)
{
	t_point_2d	*new_p;
	int			x;
	int			y;

	x = rint(p->x);
	y = rint(p->y);
	new_p = fdf_create_point_2d(x, y);
	return (new_p);
}
