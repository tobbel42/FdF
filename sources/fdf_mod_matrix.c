/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mod_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:55:16 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/03 13:44:01 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_mod_matrix(t_fdf *fdf)
{
	if (fdf->m)
		fdf_delete_matrix(fdf->m);
	fdf->m = fdf_create_new_matrix(fdf);
	fdf_copy_matrix(fdf);
	fdf_trans(fdf);	
	fdf_spread_matrix(fdf);
	fdf_rotate_x(fdf);
	fdf_rotate_y(fdf);
	fdf_rotate_z(fdf);
	
}
