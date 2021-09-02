/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_delete_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:55 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:21:01 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//frees a given matrix object and all its elements
*/
void	fdf_delete_matrix(t_point_3d ***m)
{
	int	x;
	int	y;

	if (!m)
		return ;
	y = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			free(m[y][x]);
			x++;
		}
		free(m[y]);
		y++;
	}
	free(m);
}
