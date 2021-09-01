/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:58:44 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/01 18:03:41 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h> //todo remove
# include <math.h>
# include <fcntl.h>

typedef struct point_2d
{
	int		x;
	int		y;
}	t_point_2d;
typedef struct point_3d
{
	float	x;
	float	y;
	float	z;
}	t_point_3d;
typedef struct fdf
{
	void		*ptr;
	void		*win;
	t_point_3d	***matrix;
	float		x_len;
	float		y_len;
	int			x;
	int			y;
	int			z;
}	t_fdf;
t_fdf		*fdf_create_new_window(float x, float y, float z);
int			hook_keydown(int key, t_fdf *fdf);
t_point_2d	*fdf_create_point_2d(int x, int y);
t_point_3d	*fdf_create_point_3d(float x, float y, float z);
t_point_2d	*fdf_to_2d(t_point_3d *p, t_fdf *fdf);
void		fdf_bresenham(t_point_2d *p1, t_point_2d *p2, t_fdf *fdf);
t_point_3d	***fdf_file_to_matrix(int fd);
void		fdf_init_matrix(t_fdf *fdf, t_point_3d ***matrix);
void		fdf_isometric(t_fdf *fdf);
t_point_2d	*fdf_project_orto(t_point_3d *p);
void	fdf_rotate_x(t_fdf *fdf, int deg);
void	fdf_rotate_y(t_fdf *fdf, int deg);
void	fdf_draw_screen(t_fdf *fdf);
#endif