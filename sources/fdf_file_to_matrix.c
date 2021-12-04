/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_to_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:00:05 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/04 21:31:51 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_delete_c_matrix(char ***char_matrix)
{
	int		x;
	int		y;

	y = 0;
	if (!char_matrix)
		return ;
	while (char_matrix[y])
	{
		x = 0;
		while (char_matrix[y][x])
		{
			free(char_matrix[y][x]);
			x++;
		}
		free(char_matrix[y]);
		y++;
	}
	free(char_matrix);
}

static int	append_to_matrix(t_fdf *fdf, char **tab)
{
	int		i;
	char	***new_matrix;

	new_matrix = (char ***)ft_calloc((fdf->y_len + 2), sizeof(char **));
	if (!new_matrix)
		return (1);
	i = 0;
	while (i < fdf->y_len)
	{
		new_matrix[i] = fdf->c_m[i];
		i++;
	}
	fdf->y_len += 1;
	new_matrix[i] = tab;
	free(fdf->c_m);
	fdf->c_m = new_matrix;
	return (0);
}

static int	char_matrix(t_fdf *fdf, int fd)
{
	char	*line;
	char	**tab;

	fdf->c_m = (char ***)ft_calloc(sizeof(char **), 1);
	if (!fdf->c_m)
		return (1);
	line = get_next_line(fd);
	while (line && fdf->c_m)
	{
		tab = ft_split(line, ' ');
		if (!tab)
			return (1);	
		if (append_to_matrix(fdf, tab))
		{
			free(tab);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

static t_point_3d	**get_row(char **c_row, int y)
{
	int			len;
	int			x;
	t_point_3d	**row;

	x = 0;
	len = 0;
	if (!c_row)
		return (NULL);
	while (c_row[len])
		len++;
	row = (t_point_3d **)ft_calloc((len + 1), sizeof(t_point_3d *));
	if (!row)
		return (NULL);
	while (c_row[x] && ft_strncmp(c_row[x], "\n", 1))
	{
		row[x] = fdf_create_point_3d(x,  y, -1 * ft_atoi(c_row[x])); // todo read colour
		x++;
	}
	return (row);
}

/*
//transforms the given file into a matrix of 3d points
*/
int	fdf_file_to_matrix(t_fdf *fdf, int fd)
{
	int			y;

	if (char_matrix(fdf, fd))
		return (1);

	fdf->og_m = (t_point_3d ***)ft_calloc((fdf->y_len + 1) , sizeof(t_point_3d **));
	if (!fdf->og_m)
		return (1);
	y = 0;
	while (y < fdf->y_len)
	{	
		fdf->og_m[y] = get_row(fdf->c_m[y], y);
		if (!fdf->og_m[y])
			return (1);
		y++;
	}
	while (fdf->og_m[0][fdf->x_len])
		fdf->x_len++;
	return (0);
}
