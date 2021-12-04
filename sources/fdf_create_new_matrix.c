/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_new_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:07:44 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 17:09:30 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point_3d	**create_row(t_fdf *fdf)
{
	int			x;
	t_point_3d	**row;

	row = (t_point_3d **)malloc((fdf->x_len + 1) * sizeof(t_point_3d *));
	if (!row)
		return (NULL);
	x = 0;
	row[fdf->x_len] = NULL;
	while (x < fdf->x_len)
	{
		row[x] = fdf_create_point_3d(0, 0, 0);
		if (!row[x])
			return (row);
		x++;
	}
	return (row);
}

/*
//creates a new matrix with the size of the original matrix;
*/
t_point_3d	***fdf_create_new_matrix(t_fdf *fdf)
{
	int			y;
	t_point_3d	***m;

	m = (t_point_3d ***)malloc((fdf->y_len + 1) * sizeof(t_point_3d **));
	if (!m)
		return (NULL);
	m[fdf->y_len] = NULL;
	y = 0;
	while (y < fdf->y_len)
	{
		m[y] = create_row(fdf);
		if (!m[y])
			return (NULL);
		y++;
	}
	return (m);
}
