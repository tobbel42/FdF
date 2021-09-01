/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:18:58 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 15:01:43 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	lenghts(t_fdf *fdf)
{
	int		x_len;
	int		y_len;

	x_len = 0;
	while (fdf->matrix[0][x_len])
		x_len++;
	y_len = 0;
	while (fdf->matrix[y_len])
		y_len++;
	fdf->x_len = x_len;
	fdf->y_len = y_len;
}

void	spread(t_fdf *fdf)
{
	float	factor;
	int		y;
	int		x;

	y = 0;
	factor = 1080 / hypot(fdf->x_len, fdf->y_len);
	while (fdf->matrix[y])
	{
		x = 0;
		while (fdf->matrix[y][x])
		{
			fdf->matrix[y][x]->x *= factor;
			fdf->matrix[y][x]->y *= factor;
			fdf->matrix[y][x]->z *= factor;
			x++;
		}
		y++;
	}
	fdf->x_len *= factor;
	fdf->y_len *= factor;
}

void	center(t_fdf *fdf)
{
	int		x;
	int		y;
	float	c_x;
	float	c_y;

	y = 0;
	while (fdf->matrix[y])
	{
		x = 0;
		while (fdf->matrix[y][x])
		{
			fdf->matrix[y][x]->x += 960 - (fdf->x_len / 2);
			fdf->matrix[y][x]->y += 540 - (fdf->y_len / 2);
			x++;
		}
		y++;
	}
	c_x = fdf->x_len / 2;
	c_y = fdf->y_len / 2;
}

void	fdf_init_matrix(t_fdf *fdf, t_point_3d ***matrix)
{
	fdf->matrix = matrix;
	lenghts(fdf);
	spread(fdf);
	center(fdf);
}
