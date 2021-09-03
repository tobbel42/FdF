/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_copy_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:30:35 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/03 10:59:13 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//copies the values of the og matrix over to the new matrix m
*/
void	fdf_copy_matrix(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (fdf->og_matrix[y])
	{
		x = 0;
		while (fdf->og_matrix[y][x])
		{
			fdf->m[y][x]->x = fdf->og_matrix[y][x]->x;
			fdf->m[y][x]->y = fdf->og_matrix[y][x]->y;
			fdf->m[y][x]->z = fdf->og_matrix[y][x]->z;
			x++;
		}
		y++;
	}
}
