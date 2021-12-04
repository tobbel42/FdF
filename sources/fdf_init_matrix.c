/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:18:58 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 20:58:27 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	center(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (fdf->og_m[y])
	{
		x = 0;
		while (fdf->og_m[y][x])
		{
			fdf->og_m[y][x]->x -= ((float)(fdf->x_len - 1) / 2);
			fdf->og_m[y][x]->y -= ((float)(fdf->y_len - 1) / 2);
			x++;
		}
		y++;
	}
}

/*
//initialize the matrix into an isometric view
*/
int	fdf_init_matrix(t_fdf *fdf)
{
	if (!fdf->og_m)
		return (1);
	center(fdf);
	fdf->x_rot = 45;
	fdf->y_rot = -30;
	fdf->z_rot = 35.264;
	fdf->x_trans = 0;
	fdf->y_trans = 0;
	return (0);
}
