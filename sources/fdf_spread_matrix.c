/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_spread_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:56:08 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 15:39:21 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//applies the zoom to the matrix
*/
void	fdf_spread_matrix(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (fdf->og_matrix[y])
	{
		x = 0;
		while (fdf->og_matrix[y][x])
		{
			fdf->m[y][x]->x *= fdf->spread;
			fdf->m[y][x]->y *= fdf->spread;
			fdf->m[y][x]->z *= fdf->spread;
			x++;
		}
		y++;
	}
}
