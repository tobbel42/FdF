/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:58:44 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/07 12:21:13 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../minilibx_macos/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
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
	t_point_2d	*c;
	int			spread;
	int			x_len;
	int			y_len;
	int			x_trans;
	int			y_trans;
	float		x_rot;
	float		y_rot;
	float		z_rot;
}	t_fdf;
typedef struct b
{
	int		d[2];
	int		s[2];
}	t_b;
t_fdf		*fdf_create_new_window(int x, int y);
int			hook_keydown(int key, t_fdf *fdf);
t_point_2d	*fdf_create_point_2d(int x, int y);
t_point_3d	*fdf_create_point_3d(float x, float y, float z);
void		fdf_bresenham(t_point_2d *p1, t_point_2d *p2, t_fdf *fdf);
t_point_3d	***fdf_file_to_matrix(int fd);
int			fdf_init_matrix(t_fdf *fdf, t_point_3d ***matrix);
void		fdf_isometric(t_fdf *fdf);
t_point_2d	*fdf_project_orto(t_point_3d *p);
void		fdf_rotate_x(t_fdf *fdf);
void		fdf_rotate_y(t_fdf *fdf);
void		fdf_rotate_z(t_fdf *fdf);
void		fdf_trans(t_fdf *fdf);
void		fdf_draw_screen(t_fdf *fdf);
t_point_3d	***fdf_create_new_matrix(t_fdf *fdf);
void		fdf_delete_matrix(t_point_3d ***m);
void		fdf_copy_matrix(t_fdf *fdf);
void		fdf_mod_matrix(t_fdf *fdf);
void		fdf_spread_matrix(t_fdf *fdf);
int			fdf_errors(int i, char *argv);
void		fdf_instructions_bonus(t_fdf *fdf);
int			fdf_check_lines(t_fdf *fdf);

#endif