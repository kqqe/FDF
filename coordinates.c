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
	t_point *f;
	f = (t_point*)param;  

	if (press_key == 13)//движение фигуры назад w
	{	
		f->angle += 1; 
		f->x = f->x * cos(f->angle) + f->z * sin(f->angle);
	 	f->y = f->y;
		f->z = - f->x * sin(f->angle) + f->z * cos(f->angle);
	}
	if (press_key == 1)// на себя s 
	{
		f->angle+=1; 
		f->x = f->x * cos(f->angle) + f->z * sin(f->angle);
		f->y = f->y;
		f->z = - f->x * sin(f->angle) + f->z * cos(f->angle);
	}
	if (press_key == 0)//left a
	{
		f->angle+=1; 
		f->x = f->x; 
		f->y = f->y * cos(f->angle) + f->z * sin(f->angle);
		f->z = -f->y * sin(f->angle) + f->z * cos(f->angle);
	}
	if (press_key == 2)//right d
	{
		f->angle+=1; 
		f->x = f->x; 
		f->y = f->y * cos(f->angle) + f->z * sin(f->angle);
		f->z = -f->y * sin(f->angle) + f->z * cos(f->angle);
	}
	return (0);
}
