/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:15:23 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 20:38:54 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		*fdf;

	fdf = fdf_init_fdf(argc, argv);
	
	
	fdf_mod_matrix(fdf);
	fdf_draw_screen(fdf);
	fdf_instructions(fdf);

	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);

	return (0);
}
