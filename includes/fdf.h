/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:58:44 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 21:20:50 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
//FdF specific errors
*/
# define ERR_ARG 1
# define ERR_OPEN 2
# define ERR_PARSE 3
# define ERR_WIN 4
# define ERR_LINE 5
# define ERR_MEM 6

/*
//library includes
//
//-> minilibx -> basic graphics library
//
//-> get_next_line -> for reading files (prior project) 
//
//-> libft -> basic util function (prior project)
//
*/
# include "../minilibx_macos/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct point_2d
{
	int		x;
	int		y;
	int		col;
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
	int			height;
	int			width;

	void		*img;
	void		*img_addr;
	int			img_ll;
	int			img_bpp;
	int			img_end;

	t_point_3d	***og_matrix;
	t_point_3d	***m;
	int			x_len;
	int			y_len;

	int			spread;
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


t_point_2d	*fdf_create_point_2d(int x, int y);
t_point_3d	*fdf_create_point_3d(float x, float y, float z);
t_point_3d	***fdf_create_new_matrix(t_fdf *fdf);
void		fdf_delete_matrix(t_point_3d ***m);



void		fdf_mod_matrix(t_fdf *fdf);



void		fdf_spread_point(t_fdf *fdf, int x, int y);
void		fdf_trans_point(t_fdf *fdf, int x, int y);
void		fdf_x_rotate(t_point_3d *p, float rad);
void		fdf_y_rotate(t_point_3d *p, float rad);
void		fdf_z_rotate(t_point_3d *p, float rad);



void		fdf_draw_screen(t_fdf *fdf);


t_point_2d	*fdf_project_orto(t_point_3d *p);
void		fdf_bresenham(t_point_2d *p1, t_point_2d *p2, t_fdf *fdf);


void		fdf_instructions(t_fdf *fdf);

int			hook_keydown(int key, t_fdf *fdf);


t_fdf		*fdf_init_fdf(int argc, char **argv);
int			fdf_read_file(t_fdf *fdf, int argc, char **argv);
t_point_3d	***fdf_file_to_matrix(int fd);
int			fdf_init_matrix(t_fdf *fdf, t_point_3d ***matrix);
int			fdf_check_lines(t_fdf *fdf);
int			fdf_init_m(t_fdf *fdf);
int			fdf_create_new_window(t_fdf *fdf);
void		fdf_clean_fdf(t_fdf *fdf);


int			fdf_errors(t_fdf *fdf, int i, char *argv);


#endif