/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:50:09 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 19:34:16 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_clean_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->m)
		fdf_delete_matrix(fdf->m);
	fdf->m = NULL;
	if (fdf->c_m)
		fdf_delete_c_matrix(fdf->c_m);
	fdf->c_m = NULL;
	if (fdf->og_m)
		fdf_delete_matrix(fdf->og_m);
	fdf->og_m = NULL;
	if (fdf->img)
		mlx_destroy_image(fdf->ptr, fdf->img);
	fdf->img = NULL;
	if (fdf->win)
		mlx_destroy_window(fdf->ptr, fdf->win);
	fdf->win = NULL;
}
