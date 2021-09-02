/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:29:51 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:33:53 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//translates the matrix by the given values in x and y direction
*/
void	fdf_trans(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (fdf->m[y])
	{
		x = 0;
		while (fdf->m[y][x])
		{
			fdf->m[y][x]->x += (float)fdf->x_trans;
			fdf->m[y][x]->z += (float)fdf->y_trans;
			x++;
		}
		y++;
	}	
}
