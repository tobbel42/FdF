/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:22:29 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/03 14:26:58 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hook_keydown(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		//system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	else if (key == 12)
		fdf->z_rot -= 15;
	else if (key == 13)
		fdf->x_rot -= 15;
	else if (key == 14)
		fdf->z_rot += 15;
	else if (key == 0)
		fdf->y_rot += 15;
	else if (key == 1)
		fdf->x_rot += 15;
	else if (key == 2)
		fdf->y_rot -= 15;
	else if (key == 24)
		fdf->spread++;
	else if (key == 27)
	{
		if (fdf->spread > 1)
			fdf->spread--;
	}
	else if (key == 126)
		fdf->y_trans -= (float)fdf->y_len / 10 + 1;
	else if (key == 125)
		fdf->y_trans += (float)fdf->y_len / 10 + 1;
	else if (key == 123)
		fdf->x_trans -= (float)fdf->x_len / 10 + 1;
	else if (key == 124)
		fdf->x_trans += (float)fdf->x_len / 10 + 1;
	else
		printf("rotx: %.2f, roty: %.2f, rotz: %.2f\nx_trans: %i, y_trans: %i", fdf->x_rot, fdf->y_rot, fdf->z_rot, fdf->x_trans, fdf->y_trans);
	fdf_mod_matrix(fdf);
	fdf_draw_screen(fdf);
	return (0);
}
