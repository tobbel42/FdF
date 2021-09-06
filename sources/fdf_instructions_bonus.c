/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_instructions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:28:49 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:43:02 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

/*
//prints the list of keybindings onto the screen
*/
void	fdf_instructions_bonus(t_fdf *fdf)
{
	mlx_string_put(fdf->ptr, fdf->win, 10, 10, 0x00ee5522, "ECS = quit");
	mlx_string_put(fdf->ptr, fdf->win, 10, 30, 0x00ee5522, "W/S = rotate x");
	mlx_string_put(fdf->ptr, fdf->win, 10, 50, 0x00ee5522, "A/D = rotate y");
	mlx_string_put(fdf->ptr, fdf->win, 10, 70, 0x00ee5522, "Q/E = rotate z");
	mlx_string_put(fdf->ptr, fdf->win, 10, 90, 0x00ee5522, "+/- = zoom");
	mlx_string_put(fdf->ptr, fdf->win, 10, 110, 0x00ee5522, "ARROWS = move");
}
