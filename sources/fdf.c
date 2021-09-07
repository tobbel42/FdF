/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:15:23 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/07 12:23:44 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_point_3d	***matrix;
	int			fd;

	if (argc != 2)
		return (fdf_errors(1, argv[0]));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (fdf_errors(2, argv[0]));
	matrix = fdf_file_to_matrix(fd);
	fdf = fdf_create_new_window(1920, 1080);
	if (fdf == 0)
		return (fdf_errors(4, argv[0]));
	if (fdf_init_matrix(fdf, matrix))
		return (fdf_errors(3, argv[0]));
	if (fdf_check_lines(fdf) == -1)
		return (fdf_errors(5, argv[0]));
	fdf_mod_matrix(fdf);
	fdf_draw_screen(fdf);
	fdf_instructions(fdf);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);
	exit(0);
	return (0);
}
