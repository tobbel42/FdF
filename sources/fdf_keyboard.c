/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:22:29 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 18:13:27 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hook_keydown(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
	{
		system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	else if (key == 13)
		fdf_rotate_x(fdf, -15);
	else if (key == 0)
		fdf_rotate_y(fdf, -15);
	else if (key == 1)
		fdf_rotate_x(fdf, 15);
	else if (key == 2)
		fdf_rotate_y(fdf, 15);
	fdf_draw_screen(fdf);
	return (0);
}
