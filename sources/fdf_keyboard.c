/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:52:31 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:44:08 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//executes the keycommand
*/
int	hook_keydown(int key, t_fdf *fdf)
{
	int		dummy;

	dummy = fdf->x_len;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
