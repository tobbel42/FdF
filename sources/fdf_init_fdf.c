/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:28:02 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 21:10:10 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//creates a copy of the original matrix
*/
int	fdf_init_m(t_fdf *fdf)
{
	if (fdf->m)
		fdf_delete_matrix(fdf->m);
	fdf->m = fdf_create_new_matrix(fdf);
	if (fdf->m == NULL)
		return (1);
	return (0);
}

/*
//creates and initializes the fdf struct,
*/
t_fdf	*fdf_init_fdf(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
	if (!fdf)
		fdf_errors(fdf, ERR_MEM, argv[0]);
	fdf->width = 1920;
	fdf->height = 1080;
	fdf->spread = 1;
	fdf_read_file(fdf, argc, argv);
	if (fdf_init_m(fdf))
		fdf_errors(fdf, ERR_MEM, argv[0]);
	if (fdf_create_new_window(fdf))
		fdf_errors(fdf, ERR_WIN, argv[0]);
	return (fdf);
}