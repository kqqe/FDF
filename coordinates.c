/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:31:08 by pben              #+#    #+#             */
/*   Updated: 2019/04/09 19:39:13 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		control(int press_key, void *param)
{
	t_pmtx *pmtx;
	t_point *f;
	
	pmtx = (t_pmtx*)param;
	if (press_key == 126 || press_key == 125 || press_key == 123 || press_key == 124 || press_key == 6)
		arrow(press_key, pmtx);
	if (press_key == 69)
		zoom_plus(pmtx);
	if (press_key == 78)
		zoom_minus(pmtx);
	if (press_key == 13 || press_key == 1 || press_key == 0 || press_key == 2 ||
	 	press_key == 83 || press_key == 84 || press_key == 85 || press_key == 86 ||
		press_key == 87 || press_key == 88)
		rotate(press_key, pmtx);
	mlx_clear_window(pmtx->img->mlx_ptr, pmtx->img->win_ptr);
	draw_map(pmtx, pmtx->color);
	return (0);
}

void	arrow(int press_key, t_pmtx *pmtx)
{
	int			i;
	int			j;
	t_point		*f;

	i = 0;
	while (i < pmtx->size_y) 
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			f = pmtx->mtx[i][j];
			if (press_key == 126)
				f->y -= 50;
			else if (press_key == 125)
				f->y += 50;
			else if (press_key == 123)
				f->x -= 50;
			else if (press_key == 124)
				f->x += 50;
			j++;
		}
		i++;
	}
}

void		center_map(t_pmtx *pmtx)
{
	t_point diff;
	int i = 0;
	int j = 0;

	diff = *(pmtx->mtx[(pmtx->size_y)/2][(pmtx->size_x)/2]);
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

void		rotate(int press_key, t_pmtx *pmtx)
{
	int			i;
	int			j;
	t_point		*f;

	i = 0;
	while (i < pmtx->size_y) 
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			f = pmtx->mtx[i][j];
			if (press_key == 83 || press_key == 84 || press_key == 85)
				rotate2(press_key, pmtx, f);
			j++;
		}
		i++;
	}
	center_map(pmtx);
}

void		rotate2(int press_key, t_pmtx *pmtx, t_point *f)
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
		f->z = - xx * sin(pmtx->angle) + zz * cos(pmtx->angle);
	}
	if (press_key == 85)
	{
		f->x = xx * cos(pmtx->angle) - yy  * sin(pmtx->angle);
		f->y = xx * sin(pmtx->angle) + yy * cos(pmtx->angle);	
	}
}
