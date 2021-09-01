/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_point_3d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:58:45 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/30 12:00:31 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/*
//creates a 3d point with the given coordinates
*/
t_point_3d	*fdf_create_point_3d(float x, float y, float z)
{
	t_point_3d	*p;

	p = (t_point_3d *)malloc(sizeof(t_point_3d));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}
