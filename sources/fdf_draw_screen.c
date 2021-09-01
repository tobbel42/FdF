/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:54:57 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 18:03:32 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_draw_screen(t_fdf *fdf)
{
	int	i;
	int j;
	t_point_2d	*p1;
	t_point_2d	*p2;
	t_point_2d	*p3;

	mlx_clear_window(fdf->ptr, fdf->win);
	i = 0;
	while (fdf->matrix[i])
	{
		j = 0;
		while (fdf->matrix[i][j])
		{
			p1 = fdf_project_orto(fdf->matrix[i][j]);
			if (j > 0)
			{
				p2 = fdf_project_orto(fdf->matrix[i][j - 1]);
				fdf_bresenham(p1, p2, fdf);
				free(p2);
			}
			if (i > 0)
			{
				p3 = fdf_project_orto(fdf->matrix[i - 1][j]);
				fdf_bresenham(p1, p3, fdf);
				free(p3);
			}
			free(p1);
			j++;
		}
		i++;
	}
}