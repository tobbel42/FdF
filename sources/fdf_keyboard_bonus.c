/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:22:29 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:43:51 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	rota(int key, t_fdf *fdf)
{
	if (key == 12)
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
}

/*
//executes the keycommand, then redraws the screen
*/
int	hook_keydown(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		rota(key, fdf);
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
	fdf_mod_matrix(fdf);
	fdf_draw_screen(fdf);
	fdf_instructions_bonus(fdf);
	return (0);
}
