/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:52:31 by tgrossma          #+#    #+#             */
/*   Updated: 2022/07/19 11:38:00 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//executes the keycommand
*/
int	hook_keydown(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		fdf_clean_fdf(fdf);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
