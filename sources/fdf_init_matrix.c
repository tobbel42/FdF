/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:18:58 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/03 15:11:05 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	lenghts(t_fdf *fdf)
{
	int		x_len;
	int		y_len;

	x_len = 0;
	while (fdf->og_matrix[0][x_len])
		x_len++;
	y_len = 0;
	while (fdf->og_matrix[y_len])
		y_len++;
	fdf->x_len = x_len;
	fdf->y_len = y_len;
}

static void	center(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (fdf->og_matrix[y])
	{
		x = 0;
		while (fdf->og_matrix[y][x])
		{
			fdf->og_matrix[y][x]->x -= (float)fdf->x_len / 2;
			fdf->og_matrix[y][x]->y -= (float)fdf->y_len / 2;
			x++;
		}
		y++;
	}
}

static void	spread(t_fdf *fdf) //todo
{
	int		y_max;
	int		x_max;
	float	hypo;

	hypo = hypot(fdf->x_len, fdf->y_len);
	y_max = rint((float)fdf->screen_center->y * 2.4 / hypo);
	x_max = rint((float)fdf->screen_center->x * 2.4 / hypo);
	if (y_max >= x_max)
		fdf->spread = x_max;
	else
		fdf->spread = y_max;
}

void	fdf_init_matrix(t_fdf *fdf, t_point_3d ***og_matrix)
{
	fdf->og_matrix = og_matrix;
	fdf->m = NULL;
	lenghts(fdf);
	center(fdf);
	spread(fdf);
	fdf->cam->x = (-1) * fdf->spread * fdf->x_len;
	fdf->cam->y = (-1) * fdf->spread * fdf->y_len;
	fdf->cam->z = hypot(fdf->cam->x, fdf->cam->y);
	fdf->x_rot = -35.264;
	fdf->y_rot = -45;
	fdf->z_rot = -30;
	fdf->x_trans = 0;
	fdf->y_trans = 0;
}
