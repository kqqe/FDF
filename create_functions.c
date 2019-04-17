/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:44:30 by pben              #+#    #+#             */
/*   Updated: 2019/04/17 17:32:04 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_create_point(double x, double y, double z)
{
	t_point		*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_line		ft_create_line(t_point *p1, t_point *p2)
{
	t_line		line;

	line.p0 = *p1;
	line.p1 = *p2;
	line.len_x = fabs(line.p0.x - line.p1.x);
	line.len_y = fabs(line.p0.y - line.p1.y);
	line.dx = (line.p1.x - line.p0.x) >= 0 ? 1 : -1;
	line.dy = (line.p1.y - line.p0.y) >= 0 ? 1 : -1;
	return (line);
}

t_pmtx		*ft_create_pmtx(int size_x, int size_y)
{
	t_pmtx		*pmtx;

	pmtx = (t_pmtx*)malloc(sizeof(t_pmtx));
	pmtx->size_x = size_x;
	pmtx->size_y = size_y;
	pmtx->mtx = (t_point***)malloc(sizeof(t_point**) * size_y);
	while (size_y--)
	{
		pmtx->mtx[size_y] = (t_point**)malloc(sizeof(t_point*) * size_x);
	}
	pmtx->angle = 0.5;
	pmtx->scope = 2.0;
	pmtx->color = 0x0000ff00;
	pmtx->flag = 0;
	return (pmtx);
}
