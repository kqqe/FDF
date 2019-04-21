/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:31:08 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 20:23:25 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			center_map(t_pmtx *pmtx)
{
	t_point		diff;
	int			i;
	int			j;

	i = 0;
	diff = *(pmtx->mtx[(pmtx->size_y) / 2][(pmtx->size_x) / 2]);
	i = 0;
	while (i < pmtx->size_y)
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			pmtx->mtx[i][j]->x -= diff.x - 470;
			pmtx->mtx[i][j]->y -= diff.y - 470;
			j++;
		}
		i++;
	}
}

void			ft_tolya(t_pmtx *pmtx, int i, int j)
{
	pmtx->mtx[i][j]->x = pmtx->mtx1[i][j]->x;
	pmtx->mtx[i][j]->y = pmtx->mtx1[i][j]->y;
	pmtx->mtx[i][j]->z = pmtx->mtx1[i][j]->z;
	pmtx->mtx[i][j]->color = pmtx->mtx1[i][j]->color;
}

void			rotate(int press_key, t_pmtx *pmtx)
{
	int			i;
	int			j;
	t_point		*f;

	i = 0;
	if (pmtx->flag_button == 1)
		return ;
	while (i < pmtx->size_y)
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			f = pmtx->mtx[i][j];
			if (press_key == 83 || press_key == 84 || press_key == 85)
				rotate2(press_key, pmtx, f);
			if (press_key == 34 || press_key == 31 || press_key == 35)
			{
				isometry(press_key, f);
				pmtx->flag_button = 1;
			}
			j++;
		}
		i++;
	}
	center_map(pmtx);
}

void			rotate2(int press_key, t_pmtx *pmtx, t_point *f)
{
	double		xx;
	double		yy;
	double		zz;

	xx = f->x;
	yy = f->y;
	zz = f->z;
	if (press_key == 83)
	{
		f->y = yy * cos(pmtx->angle) - zz * sin(pmtx->angle);
		f->z = yy * sin(pmtx->angle) + zz * cos(pmtx->angle);
	}
	if (press_key == 84)
	{
		f->x = xx * cos(pmtx->angle) + zz * sin(pmtx->angle);
		f->z = -xx * sin(pmtx->angle) + zz * cos(pmtx->angle);
	}
	if (press_key == 85)
	{
		f->x = xx * cos(pmtx->angle) - yy * sin(pmtx->angle);
		f->y = xx * sin(pmtx->angle) + yy * cos(pmtx->angle);
	}
}

void			isometry(int press_key, t_point *f)
{
	double		xx;
	double		yy;
	double		zz;

	xx = f->x;
	yy = f->y;
	zz = f->z;
	if (press_key == 34)
	{
		f->x = (xx + yy) * cos(0.523599);
		f->y = -f->z + (xx - yy) * sin(0.523599) * -1;
	}
	if (press_key == 31)
	{
		f->x = f->x - (f->z / 2) * cos(45) * 3.17;
		f->y = f->y - (f->z / 2) * sin(45) * 1.96;
		f->z = 0;
	}
}
