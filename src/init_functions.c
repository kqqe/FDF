/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:44:30 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 20:26:06 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pmtx		*ft_init_pmtx(int **mtx, int size_x, int size_y)
{
	t_pmtx	*tx;
	int		i;
	int		j;
	t_point	***dest;
	t_point	***mtx1;

	tx = ft_create_pmtx(size_x, size_y);
	tx->of = 325;
	dest = tx->mtx;
	mtx1 = tx->mtx1;
	i = 0;
	while (i < tx->size_y)
	{
		j = 0;
		while (j < tx->size_x)
		{
			dest[i][j] = ft_create_point(((j + 1) * 15) + tx->of, ((i + 1) * 15)
			+ tx->of, (mtx[i][j] * 5) + tx->of);
			mtx1[i][j] = ft_create_point(((j + 1) * 15) + tx->of, ((i + 1) * 15)
			+ tx->of, (mtx[i][j] * 5) + tx->of);
			j++;
		}
		i++;
	}
	return (tx);
}

void		zoom_plus(t_pmtx *pmtx)
{
	t_point	diff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (i == 0 && j == 0)
		diff = *(pmtx->mtx[0][0]);
	while (i < pmtx->size_y)
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			pmtx->mtx[i][j]->x *= pmtx->scope;
			pmtx->mtx[i][j]->x -= diff.x;
			pmtx->mtx[i][j]->y *= pmtx->scope;
			pmtx->mtx[i][j]->y -= diff.y;
			j++;
		}
		i++;
	}
	center_map(pmtx);
}

void		zoom_minus(t_pmtx *pmtx)
{
	t_point	diff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (i == 0 && j == 0)
		diff = *(pmtx->mtx[0][0]);
	while (i < pmtx->size_y)
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			pmtx->mtx[i][j]->x += diff.x;
			pmtx->mtx[i][j]->x /= pmtx->scope;
			pmtx->mtx[i][j]->y += diff.y;
			pmtx->mtx[i][j]->y /= pmtx->scope;
			j++;
		}
		i++;
	}
	center_map(pmtx);
}
