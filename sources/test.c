/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:32:18 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/27 15:55:21 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(void)
{
	t_fdf	*fdf;
	t_point *p1;
	t_point	*p2;
	t_point *p3;
	t_point	*p4;
	int i = 1;

	fdf = fdf_create_new_window();
	if (fdf == 0)
		return (0);
	p1 = fdf_create_point(500 + (100 * cosf(i / 100)), 500 + (200 * sinf(i / 100)));
	p3 = fdf_create_point(1000 + (100 * cosf(i / 100)), 500 + (200 * sinf(i / 100)));
	while (i < 5000)
	{
		p2 = p1;
		p4 = p3;
		p1 = fdf_create_point(500 + (100 * cosf(i / 100)), 500 + (200 * sinf(i / 100)));
		p3 = fdf_create_point(1000 + (100 * cosf(i / 100)), 500 + (200 * sinf(i / 100)));
		i++;
		fdf_bresenham(p2, p1, fdf);
		fdf_bresenham(p4, p3, fdf);
	}
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);
	exit(0);
	return (0);
}
