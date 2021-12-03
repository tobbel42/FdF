/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_copy_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:45:55 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 10:48:22 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_copy_point(t_fdf *fdf, int x, int y)
{
	fdf->m[y][x]->x = fdf->og_matrix[y][x]->x;
	fdf->m[y][x]->y = fdf->og_matrix[y][x]->y;
	fdf->m[y][x]->z = fdf->og_matrix[y][x]->z;
}