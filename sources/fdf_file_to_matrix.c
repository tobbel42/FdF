/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_to_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:00:05 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/06 16:41:47 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	***unwind_c_matrix(char ***char_matrix)
{
	int		x;
	int		y;

	y = 0;
	if (!char_matrix)
		return (NULL);
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
	return (NULL);
}

static char	***append_to_matrix(char ***matrix, char **tab)
{
	int		len;
	int		i;
	char	***new_matrix;

	len = 0;
	if (!matrix)
		return (NULL);
	while (matrix[len])
		len++;
	new_matrix = (char ***)malloc((len + 2) * sizeof(char **));
	if (!new_matrix)
		return (unwind_c_matrix(matrix));
	i = 0;
	while (i < len)
	{
		new_matrix[i] = matrix[i];
		i++;
	}
	new_matrix[i] = tab;
	new_matrix[i + 1] = NULL;
	free(matrix);
	return (new_matrix);
}

static char	***char_matrix(int fd)
{
	char	*line;
	char	**tab;
	char	***matrix;

	matrix = (char ***)malloc(sizeof(char **));
	if (!matrix)
		return (NULL);
	matrix[0] = NULL;
	line = get_next_line(fd);
	while (line && matrix)
	{
		tab = ft_split(line, ' ');
		if (!tab)
			return (unwind_c_matrix(matrix));
		matrix = append_to_matrix(matrix, tab);
		if (!matrix)
			free(tab);
		free(line);
		line = get_next_line(fd);
	}
	return (matrix);
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
	row = (t_point_3d **)malloc((len + 1) * sizeof(t_point_3d *));
	if (!row)
		return (NULL);
	row[len] = NULL;
	while (c_row[x] && ft_strncmp(c_row[x], "\n", 1))
	{
		row[x] = fdf_create_point_3d(x, y, (-1) * ft_atoi(c_row[x]));
		x++;
	}
	return (row);
}

/*
//transforms the given file into a matrix of 3d points
*/
t_point_3d	***fdf_file_to_matrix(int fd)
{
	char		***c_matrix;
	t_point_3d	***matrix;
	int			len;
	int			y;

	c_matrix = char_matrix(fd);
	if (!c_matrix)
		return (NULL);
	len = 0;
	while (c_matrix[len])
		len++;
	matrix = (t_point_3d ***)malloc((len + 1) * sizeof(t_point_3d **));
	if (!matrix)
		return (NULL);
	matrix[len] = NULL;
	y = 0;
	while (c_matrix[y])
	{	
		matrix[y] = get_row(c_matrix[y], y);
		if (!matrix[y])
			break ;
		y++;
	}	
	unwind_c_matrix(c_matrix);
	return (matrix);
}
