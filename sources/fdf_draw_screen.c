/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:54:57 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 20:00:00 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_line(t_point_2d *p1, t_point_3d *p2, t_fdf *fdf)
{
	t_point_2d	*p3;

	p3 = fdf_project_orto(p2);
	
	if (!p3)
		return ;
	fdf_bresenham(p1, p3, fdf);

	free(p3);
}

/*
//draws the transformed matrix onto the screen
*/
void	fdf_draw_screen(t_fdf *fdf)
{
	int			i;
	int			j;
	t_point_2d	*p1;

	mlx_clear_window(fdf->ptr, fdf->win);
	fdf->img = mlx_new_image(fdf->ptr, 1920, 1080);
	fdf->img_addr = mlx_get_data_addr(fdf->img, &fdf->img_bpp, &fdf->img_ll, &fdf->img_end);
	i = 0;
	while (fdf->m[i])
	{
		j = 0;
		while (fdf->m[i][j])
		{
			p1 = fdf_project_orto(fdf->m[i][j]);
			if (j > 0)
				draw_line(p1, fdf->m[i][j - 1], fdf);
			if (i > 0)
				draw_line(p1, fdf->m[i - 1][j], fdf);
			free(p1);
			
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->ptr, fdf->win, fdf->img, 0, 0);
	mlx_destroy_image(fdf->ptr, fdf->img);
	fdf->img = NULL;
}
