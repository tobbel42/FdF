/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:18:58 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:56:45 by tgrossma         ###   ########.fr       */
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

void	fdf_init_matrix(t_fdf *fdf, t_point_3d ***og_matrix)
{
	fdf->og_matrix = og_matrix;
	fdf->m = NULL;
	lenghts(fdf);
	center(fdf);
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
}
