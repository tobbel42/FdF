/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_new_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:09:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 20:13:18 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//creates a mlx-pointer and a new window, with the given size
//returns 0 on success, 1 on error; 
*/
int		fdf_create_new_window(t_fdf *fdf)
{
	fdf->ptr = mlx_init();
	if (!fdf->ptr)
		return (1);
	fdf->win = mlx_new_window(fdf->ptr, fdf->width, fdf->height, "fdf");
	if (!fdf->win)
		return (1);
	return (0);
}
