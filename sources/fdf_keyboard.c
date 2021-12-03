/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:52:31 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 20:04:23 by tgrossma         ###   ########.fr       */
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
		fdf_clean_fdf(fdf);
		fdf_clean_fdf(fdf);
		system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
