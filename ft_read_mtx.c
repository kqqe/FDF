/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_mtx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:45:43 by pben              #+#    #+#             */
/*   Updated: 2019/03/04 14:46:41 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_read_mtx(char *filename)
{
	int		fd;
	char	buf;
	int		line_count;
	int		ret;
	int		**mtx;
	char	*line;
	int		len;
	
	fd = open(filename, O_RDONLY);
	line_count = 0;

	//Считаем количество строк
	while((ret = read(fd, &buf, 1)))
	{
		if (buf == '\n')
			line_count++;
	}
	//Выделяем память под строки
	mtx = (int**)malloc(line_count * sizeof(int*));
	close(fd);
	fd = open(filename, O_RDONLY);
	int i = 0; //Счетчик для строк
	while((ret = get_next_line(fd, &line)) == 1)
	{
		char **tmp = ft_strsplit(line, ' '); //Дробим строку по пробелам
		int j;
		//Считаем количество чисел в строке
		len = 0;
		while(tmp[len])
			len++;
		mtx[i] = (int*)malloc(len * sizeof(int)); //выделяем память под i-ую строку
		//заполняем строку числами
		j = 0;
		while (j < len)
		{
			mtx[i][j] = ft_atoi(tmp[j]);// написать атои базе
			j++;
		}
		i++;
		ft_free_tab(&tmp);
		free(line);
		//ft_create_point(mtx, line_count, len);
	}
	ft_graphics(mtx, line_count, len);
	for(i = 0; i < line_count; i++)
	{
		for(int j = 0; j < len; j++)
			printf("%2d", mtx[i][j]);
		printf("\n");
	}
	close(fd);
	return (mtx);
}
