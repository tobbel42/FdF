/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:08:51 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/07 12:23:26 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
//a list of expressiv error messages
*/
int	fdf_errors(int i, char *argv)
{
	ft_putstr_fd(argv, 2);
	if (i == 1)
		ft_putendl_fd(": incorrect number of arguments", 2);
	else if (i == 2)
		ft_putendl_fd(": can not open file", 2);
	else if (i == 3)
		ft_putendl_fd(": could not parse map", 2);
	else if (i == 4)
		ft_putendl_fd(": could not create window", 2);
	else if (i == 5)
		ft_putendl_fd(": incorrect line lenght", 2);
	else
		ft_putendl_fd(": error", 2);
	return (1);
}
