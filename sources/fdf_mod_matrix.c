/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mod_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:55:16 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:58:46 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_mod_matrix(t_fdf *fdf)
{
	t_point_3d***	m;

	if (fdf->m)
		free(fdf->m);
	fdf->m = fdf_create_new_matrix(fdf);
	
	fdf_trans(fdf);
	fdf_rotate_x(fdf);
	fdf_rotate_x(fdf);
	fdf_rotate_x(fdf);
}