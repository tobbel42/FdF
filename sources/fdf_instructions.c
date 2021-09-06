/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:23:52 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:43:06 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//prints the list of keybindings onto the screen
*/
void	fdf_instructions(t_fdf *fdf)
{
	mlx_string_put(fdf->ptr, fdf->win, 10, 10, 0x00ee5522, "ECS = quit");
}
