/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:11:23 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 20:36:01 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				control(int press_key, void *param)
{
	t_pmtx		*pmtx;

	pmtx = (t_pmtx*)param;
	if (press_key == 48)
		pmtx->flag_button = 0;
	if (press_key == 53)
		close_window(pmtx);
	if (press_key == 126 || press_key == 125 ||
		press_key == 123 || press_key == 124 || press_key == 6
		|| press_key == 35)
		arrow(press_key, pmtx);
	if (press_key == 69)
		zoom_plus(pmtx);
	if (press_key == 78)
		zoom_minus(pmtx);
	if (press_key == 83 || press_key == 84
		|| press_key == 85 || press_key == 86 || press_key == 87
		|| press_key == 88 || press_key == 34 || press_key == 31
		|| press_key == 48)
		rotate(press_key, pmtx);
	mlx_clear_window(pmtx->img->mlx_ptr, pmtx->img->win_ptr);
	draw_map(pmtx);
	return (0);
}

void			arrow(int press_key, t_pmtx *pmtx)
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
			else if (press_key == 35)
				ft_tolya(pmtx, i, j);
			j++;
		}
		i++;
	}
}
