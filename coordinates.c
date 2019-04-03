/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:31:08 by pben              #+#    #+#             */
/*   Updated: 2019/03/14 17:31:10 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		control(int press_key, void *param)
{
	t_pmtx *pmtx;
	t_point *f;
	int i;
	int j;

	pmtx = (t_pmtx*)param;
	i = 0;
	while (i < pmtx->size_y)
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			f = pmtx->mtx[i][j];
			if (press_key == 13)//движение фигуры назад w
			{
				f->angle += 0.2;
				// f->x = ((int)f->x + 0.5 + (int)f->y)+0.5 * (int)cos(f->angle + 0.5);
				// f->y = ((int)f->x + 0.5 - (int)f->y)+0.5 * (int)sin(f->angle + 0.5) - (int)f->z + 0.5;
				// f->x += 0;
				// f->y -= 50;
				// f->z += 50;
				 f->x = (int)f->x + 0.5 * (int)cos(f->angle + 0.5) + (int)f->z + 0.5 * (int)sin(f->angle + 0.5);
				 f->y = (int)f->y;
				 f->z = - (int)f->x + 0.5 * (int)sin(f->angle + 0.5) + (int)f->z +0.5 * (int)cos(f->angle +0.5);
				 f->z +=2;
			}
			else if (press_key == 1)// на себя s 
			{
				f->angle+=0.2;
				f->x += 0;
				f->y += 50;
				f->z += 50;

				// f->x = f->x * cos(f->angle) + f->z * sin(f->angle);
				// f->y = f->y;
				// f->z = - f->x * sin(f->angle) + f->z * cos(f->angle);
			}
			else if (press_key == 0)//left a
			{
				f->x = (int)f->x + 0.5 - (int)f->y + 0.5 * -(int)cos(f->angle + 0.5);
				f->y = ((int)f->x + 0.5 + (int)f->y+ 0.5 * (int)sin(f->angle + 0.5) - (int)f->z + 0.5);
				// f->angle+=0.2; 
				// f->x -= 50;
				// f->y += 0;
				// f->z += 50;
				// f->x = f->x; 
				// f->y = f->y * cos(f->angle) + f->z * sin(f->angle);
				// f->z = -f->y * sin(f->angle) + f->z * cos(f->angle);
			}
			else if (press_key == 2)//right d
			{
				// f->angle+=0.2;
				f->angle+=0.2;
				f->x += 50;
				f->y -= 0;
				f->z += 50;
				// f->x = f->x; 
				// f->y = f->y * cos(f->angle) + f->z * sin(f->angle);
				// f->z = -f->y * sin(f->angle) + f->z * cos(f->angle);
			}
			j++;
		}
		i++;		
	}
	//ft_print_pmtx(pmtx);
	mlx_clear_window(pmtx->img->mlx_ptr, pmtx->img->win_ptr);
	draw_map(pmtx->size_y, pmtx->size_x, pmtx, 0x0000ff00);
	
	return (0);
}
