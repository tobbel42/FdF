/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:32:18 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/03 11:50:44 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	t_point_3d	***matrix;
	int			fd;

	if (argc != 2)
	{
		ft_putendl_fd("./fdf: incorrect number of arguments", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("./fdf: can not open file", 2);
		return (1);
	}
	matrix = fdf_file_to_matrix(fd);	
	fdf = fdf_create_new_window(1920, 1080);
	if (fdf == 0)
		return (0);
	fdf_init_matrix(fdf, matrix);
	fdf_mod_matrix(fdf);
	fdf_draw_screen(fdf);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_loop (fdf->ptr);
	exit(0);
	return (0);
}
