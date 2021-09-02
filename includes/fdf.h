/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:58:44 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/02 15:39:57 by tgrossma         ###   ########.fr       */
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
	t_point_3d	***og_matrix;
	t_point_3d	***m;
	t_point_2d	*screen_center;
	int			x_len;
	int			y_len;
	int			x_trans;
	int			y_trans;
	float		x_rot;
	float		y_rot;
	float		z_rot;
}	t_fdf;
t_fdf		*fdf_create_new_window(int x, int y);
int			hook_keydown(int key, t_fdf *fdf);
t_point_2d	*fdf_create_point_2d(int x, int y);
t_point_3d	*fdf_create_point_3d(float x, float y, float z);
void		fdf_bresenham(t_point_2d *p1, t_point_2d *p2, t_fdf *fdf);
t_point_3d	***fdf_file_to_matrix(int fd);
void		fdf_init_matrix(t_fdf *fdf, t_point_3d ***matrix);
void		fdf_isometric(t_fdf *fdf);
t_point_2d	*fdf_project_orto(t_point_3d *p);
void		fdf_rotate_x(t_fdf *fdf);
void		fdf_rotate_y(t_fdf *fdf);
void		fdf_rotate_z(t_fdf *fdf);
void		fdf_trans(t_fdf *fdf);
void		fdf_draw_screen(t_fdf *fdf);
t_point_3d	***fdf_create_new_matrix(t_fdf *fdf);
void		fdf_delete_matrix(t_point_3d ***m);

#endif