/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:22:29 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:53:46 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hook_keydown(int key, t_fdf *fdf)
{
	printf("key: %i\n", key);
	if (key == 53)
	{
		//system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	else if (key == 12)
		fdf->z_rot -= 15;
	else if (key == 13)
		fdf->x_rot += 15;
	else if (key == 14)
		fdf->z_rot += 15;
	else if (key == 0)
		fdf->y_rot -= 15;
	else if (key == 1)
		fdf->x_rot -= 15;
	else if (key == 2)
		fdf->y_rot += 15;
	//fdf_draw_screen(fdf);
	return (0);
}
