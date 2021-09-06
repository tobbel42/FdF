/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_point_2d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:07:22 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:40:49 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//creates a 2d point with the given coordinates
*/
t_point_2d	*fdf_create_point_2d(int x, int y)
{
	t_point_2d	*p;

	p = (t_point_2d *)malloc(sizeof(t_point_2d));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	return (p);
}
