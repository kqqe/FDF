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

	pmtx = (t_pmtx*)param;
	if (press_key == 126 || press_key == 125 || press_key == 123 || press_key == 124 || press_key == 6)
		arrow(press_key, pmtx);
	if (press_key == 69)
	{
		f->scope +=5;
		zoom_plus(pmtx);
	}
	if (press_key == 78)
	{
		f->scope -=5;
		zoom_minus(pmtx);
	}
	if (press_key == 13 || press_key == 1 || press_key == 0 || press_key == 2 ||
	 press_key == 83 || press_key == 84 || press_key == 85 || press_key == 86 ||
		press_key == 87 || press_key == 88)
		rotate(press_key, pmtx);
	//modul_coordinates(pmtx);
	//ft_print_pmtx(pmtx);
	//mlx_destroy_image (pmtx->img->mlx_ptr, pmtx->img->img);
	//pmtx->img->img = mlx_new_image(pmtx->img->mlx_ptr, WINDOW, WINDOW);
	//pmtx->img->addr = mlx_get_data_addr(pmtx->img->img, &pmtx->img->bts, &pmtx->img->size_line, &pmtx->img->endian);// для отрисовки через аддр
	mlx_clear_window(pmtx->img->mlx_ptr, pmtx->img->win_ptr);
	draw_map(pmtx->size_y, pmtx->size_x, pmtx, 0x0000ff00);
	//free(pmtx->mtx);
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
			//else if (press_key == 6)
				//f->y +=20;
			j++;
		}
		i++;
	}
}

static void center_map(t_pmtx *pmtx)
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

void	rotate(int press_key, t_pmtx *pmtx)
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
			double xx = f->x;
			double yy = f->y;
			double zz = f->z;
			
			if (press_key == 13)//движение фигуры назад w // true
			{	
				f->x = (xx - yy) * cos(pmtx->angle);
				f->y = (xx + yy) * sin(pmtx->angle) - f->z;
			}
			if (press_key == 1)// на себя s 
			{
				f->y = yy * cos(f->angle) - zz * cos(pmtx->angle);
				f->z = yy * sin(f->angle) + zz * cos(f->angle);
			}
			if (press_key == 0)//left a
			{
				f->y = yy * cos(f->angle) + zz * sin(pmtx->angle);
				//f->z = zz * cos(f->angle) - yy * sin(f->angle);					
			}
			if (press_key == 83)
			{
				f->y = yy * cos(pmtx->angle) - zz * sin(pmtx->angle);
				f->z = yy * sin(pmtx->angle) + zz * cos(pmtx->angle);
			}
			if (press_key == 86) //revers
			{
				f->y = yy * cos(pmtx->angle) + zz * sin(pmtx->angle);
				f->z = zz * cos(pmtx->angle) - yy * sin(pmtx->angle);	
			}
			if (press_key == 84)
			{
				f->x = xx * cos(pmtx->angle) + zz * sin(pmtx->angle);
				f->y = yy;
				f->z = - xx * sin(pmtx->angle) + zz * cos(pmtx->angle);
			}
			if (press_key == 87)//revers
			{
				f->x = xx * cos(pmtx->angle) - zz * sin(pmtx->angle);
				f->y = yy;
				f->z = xx * sin(pmtx->angle) + zz * cos(pmtx->angle);
			}

			if (press_key == 85)
			{
				f->x = xx * cos(pmtx->angle) - yy  * sin(pmtx->angle);
				f->y = xx * sin(pmtx->angle) + yy * cos(pmtx->angle);
				f->z = zz;	
			}
			j++;
		}
		i++;
	}
	center_map(pmtx);
}

void modul_coordinates(t_pmtx *pmtx)
{
	int i;
	int j;
	i = 0;
	while (i < pmtx->size_y)
	{
		j = 0;
		while (j < pmtx->size_x)
		{
			if (pmtx->mtx[i][j]->x >= WINDOW || pmtx->mtx[i][j]->y >= WINDOW || pmtx->mtx[i][j]->z >= WINDOW)
			{
				pmtx->mtx[i][j]->x -=WINDOW;
				pmtx->mtx[i][j]->y -=WINDOW;
				//pmtx->mtx[i][j]->z -=WINDOW;
			}
			if (pmtx->mtx[i][j]->x < 0 || pmtx->mtx[i][j]->y < 0 || pmtx->mtx[i][j]->z < 0)
			{
				pmtx->mtx[i][j]->x *=-1;
				pmtx->mtx[i][j]->y *=-1;
				//pmtx->mtx[i][j]->z *=-1;
			}
			j++;
		}
		i++;
	}
	
}
