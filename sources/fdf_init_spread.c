/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_spread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:58:04 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 21:30:29 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

static float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	fdf_init_spread(t_fdf *fdf)
{
	int		x;
	int		y;
	float	x_range[2];
	float	y_range[2];

	y = 0;
	x = 0;
	x_range[0] = fdf->m[y][x]->x;
	x_range[1] = fdf->m[y][x]->x;
	y_range[0] = fdf->m[y][x]->z;
	y_range[1] = fdf->m[y][x]->z;
	while (fdf->m[y])
	{
		x = 0;
		while (fdf->m[y][x])
		{
			x_range[0] = min(fdf->m[y][x]->x, x_range[0]);
			x_range[1] = max(fdf->m[y][x]->x, x_range[1]);
			y_range[0] = min(fdf->m[y][x]->z, y_range[0]);
			y_range[1] = max(fdf->m[y][x]->z, y_range[1]);
			x++;
		}
		y++;
	}
	fdf->spread = max((float)fdf->width * 0.45 / max((max(y_range[1], -1 * y_range[0])) * fdf->width / fdf->height,  max(x_range[1], -1 * x_range[0])), 3);
}
