/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:17:49 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 20:20:27 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_check_lines(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (fdf->og_matrix[y])
	{
		x = 0;
		while (fdf->og_matrix[y][x])
			x++;
		if (x != fdf->x_len)
			return (1);
		y++;
	}
	if (y != fdf->y_len)
		return (1);
	return (0);
}
