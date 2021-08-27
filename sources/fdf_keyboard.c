/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:22:29 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/27 16:04:01 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hook_keydown(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
