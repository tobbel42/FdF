/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:09:39 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 19:56:48 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_read_file(t_fdf *fdf, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		fdf_errors(fdf, ERR_ARG, argv[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fdf_errors(fdf, ERR_OPEN, argv[0]);
	if (fdf_file_to_matrix(fdf, fd))
		fdf_errors(fdf, 10, argv[0]);
	if (fdf_init_matrix(fdf))
		fdf_errors(fdf, ERR_PARSE, argv[0]);
	if (fdf_check_lines(fdf))
		fdf_errors(fdf, ERR_LINE, argv[0]);
	return (0);
}
