/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:58:44 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/27 16:03:20 by tgrossma         ###   ########.fr       */
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
typedef struct fdf
{
	void	*ptr;
	void	*win;
}	t_fdf;
typedef struct point
{
	float	x;
	float	y;
} t_point;


t_fdf	*fdf_create_new_window(void);
int		hook_keydown(int key, t_fdf *fdf);
t_point	*fdf_create_point(float x, float y);
void	fdf_bresenham(t_point *p1, t_point *p2, t_fdf *fdf);

#endif