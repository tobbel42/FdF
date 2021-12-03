/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:08:51 by tgrossma          #+#    #+#             */
/*   Updated: 2021/12/03 20:42:22 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//a list of expressiv error messages
*/
int	fdf_errors(t_fdf *fdf, int i, char *argv)
{
	ft_putstr_fd(argv, 2);
	if (i == ERR_ARG)
		ft_putendl_fd(": incorrect number of arguments", 2);
	else if (i == ERR_OPEN)
		ft_putendl_fd(": can not open file", 2);
	else if (i == ERR_PARSE)
		ft_putendl_fd(": could not parse map", 2);
	else if (i == ERR_WIN)
		ft_putendl_fd(": could not create window", 2);
	else if (i == ERR_LINE)
		ft_putendl_fd(": incorrect line lenght", 2);
	else if (i == ERR_MEM)
		ft_putendl_fd(": malloc error", 2);
	else
		ft_putendl_fd(": error", 2);
	fdf_clean_fdf(fdf);
	exit(EXIT_FAILURE);
}
