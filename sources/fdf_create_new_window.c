/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_new_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:09:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:39:13 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*fdf_create_new_window(int x, int y)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->ptr = mlx_init();
	if (!fdf->ptr)
	{
		free(fdf);
		return (NULL);
	}
	fdf->win = mlx_new_window(fdf->ptr, x, y, "fdf");
	fdf->screen_center = fdf_create_point_2d(x / 2, y / 2);
	if (!fdf->win || !fdf->screen_center)
	{
		if (fdf->screen_center)
			free(fdf->screen_center);
		if(fdf->win)
			free(fdf->win);
		free(fdf->ptr);
		free(fdf);
		return (NULL);
	}
	return (fdf);
}
