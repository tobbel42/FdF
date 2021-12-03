/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:15:58 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 21:15:48 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_fdf		*fdf;

	fdf = fdf_init_fdf(argc, argv);
	
	
	fdf_mod_matrix(fdf);
	fdf_draw_screen(fdf);
	fdf_instructions(fdf);

	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);

	
	fdf_instructions_bonus(fdf);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);
	system("leaks fdf_bonus");
	exit(0);
	return (0);
}
