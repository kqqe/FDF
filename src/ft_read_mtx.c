/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_mtx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:45:43 by pben              #+#    #+#             */
/*   Updated: 2019/04/21 14:26:35 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_size_y(char *filename, int ***mtx)
{
	int		fd;
	int		ret;
	int		line_count;
	char	buf;

	fd = open(filename, O_RDONLY);
	line_count = 0;
	while ((ret = read(fd, &buf, 1)))
	{
		if (buf == '\n')
			line_count++;
	}
	*mtx = (int**)malloc(line_count * sizeof(int*));
	close(fd);
	return (line_count);
}

static void		ft_read_rows(int fd, int *len, int ***mtx)
{
	int		i;
	int		j;
	int		ret;
	char	*line;
	char	**tmp;

	i = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		*len = 0;
		while (tmp[*len])
			(*len)++;
		(*mtx)[i] = (int*)malloc(*len * sizeof(int));
		j = 0;
		while (j < *len)
		{
			(*mtx)[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		j = 0;
		i++;
		ft_free_tab(&tmp);
		free(line);
	}
}

static int		get_size_x(char *filename, int ***mtx)
{
	int		size_x;
	int		fd;

	fd = open(filename, O_RDONLY);
	ft_read_rows(fd, &size_x, mtx);
	close(fd);
	return (size_x);
}

int				**ft_read_mtx(char *filename)
{
	int		**mtx;
	t_pmtx	*pmtx;
	int		size_x;
	int		size_y;

	size_y = get_size_y(filename, &mtx);
	size_x = get_size_x(filename, &mtx);
	pmtx = ft_init_pmtx(mtx, size_x, size_y);
	ft_graphics(pmtx);
	return (mtx);
}
