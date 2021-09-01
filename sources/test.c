/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:32:18 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 18:04:58 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_point_3d	***matrix;

	if (argc != 2)
		return (1);
	matrix = fdf_file_to_matrix(open(argv[1], O_RDONLY));	
	fdf = fdf_create_new_window(1920, 1080, 1000);
	if (fdf == 0)
		return (0);
	fdf_init_matrix(fdf, matrix);
	fdf_isometric(fdf);
	fdf_draw_screen(fdf);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);
	system("leaks fdf");
	exit(0);
	return (0);
}
