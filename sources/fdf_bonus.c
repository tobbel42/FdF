/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:15:58 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 20:37:13 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_fdf		*fdf;

	fdf = fdf_init_fdf(argc, argv);
	fdf_mod_matrix(fdf);
	fdf_init_spread(fdf);
	fdf_mod_matrix(fdf);
	fdf_draw_screen(fdf);
	fdf_instructions_bonus(fdf);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);
	return (0);
}
