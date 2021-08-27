/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_new_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:09:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/27 16:03:16 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*fdf_create_new_window(void)
{
	t_fdf	*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (NULL);
	data->ptr = mlx_init();
	if (data->ptr == 0)
	{
		free(data);
		return (NULL);
	}
	data->win = mlx_new_window(data->ptr, 1920, 1080, "fdf");
	if (!data->win)
	{
		free(data->ptr);
		free(data);
		return (NULL);
	}
	return (data);
}
