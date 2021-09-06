/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_new_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:09:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:39:57 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//creates a new window, with the given size
*/
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
	fdf->c = fdf_create_point_2d(x / 2, y / 2);
	if (!fdf->win || !fdf->c)
	{
		if (fdf->c)
			free(fdf->c);
		if (fdf->win)
			free(fdf->win);
		free(fdf->ptr);
		free(fdf);
		return (NULL);
	}
	return (fdf);
}
