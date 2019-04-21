/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:36:21 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 20:43:21 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_name(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (str[i - 1] != 'f' && str[i - 2] != 'd'
		&& str[i - 3] != 'f' && str[i - 4] != '.')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		f;
	int		fd;
	int		**mtx;

	i = 0;
	f = 0;
	if (ac != 2 || check_name(av[1]) == 1)
	{
		write(1, "USAGE:use correct fdf file [*].fdf\n", 35);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || validation(fd) == 1)
	{
		write(1, "USAGE:use correct fdf file [*].fdf\n", 35);
		return (0);
	}
	close(fd);
	mtx = ft_read_mtx(av[1]);
	return (0);
}
