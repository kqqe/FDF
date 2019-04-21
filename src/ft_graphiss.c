/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphiss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:00:35 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/21 14:35:38 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_initclr(int line, int len, int **clr)
{
	int		i;

	i = 0;
	clr = (int**)malloc(line * sizeof(int*));
	while (i <= line)
	{
		clr[i] = (int*)malloc(len * sizeof(int));
		ft_bzero(clr[i], len);
		i++;
	}
	return (clr);
}

int		colorete(int z)
{
	int			color;

	if (z == 325)
		color = 65280;
	else if (z < 0)
		color = 0x0008080 + (z * 3 * (-1));
	else
		color = 0x0008080 + (z * 3);
	return (color);
}

void	draws(t_pmtx *mtx, int i, int j)
{
	mtx->clr[i][j] = colorete(mtx->mtx[i][j]->z);
	mtx->color = mtx->clr[i][j];
}

void	draws1(t_pmtx *mtx, int i, int j)
{
	mtx->clr1[i][j] = colorete(mtx->mtx[i][j]->z);
	mtx->color = mtx->clr1[i][j];
}

void	draw_map(t_pmtx *mtx)
{
	int			i;
	int			j;

	i = 0;
	while (i < mtx->size_y)
	{
		j = 0;
		while (j < mtx->size_x)
		{
			if (j < mtx->size_x && mtx->flag == 0)
				draws(mtx, i, j);
			if (j < mtx->size_x - 1)
				line_x(i, j, mtx);
			if (i < mtx->size_y && mtx->flag == 0)
				draws1(mtx, i, j);
			if (i < mtx->size_y - 1)
				line_y(i, j, mtx);
			j++;
		}
		i++;
	}
	menu(mtx);
	mtx->flag = 1;
}
