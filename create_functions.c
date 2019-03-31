/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:44:30 by ffahey            #+#    #+#             */
/*   Updated: 2019/03/03 18:44:47 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *ft_create_point(int x, int y, int z)
{
    t_point *point;

    point = (t_point*)malloc(sizeof(t_point));
    point->x = x;
    point->y = y;
    point->z = z;

    return (point);
}

t_line  ft_create_line(t_point *p1, t_point *p2)
{
    t_line  line;

    line.p0 = *p1;
    line.p1 = *p2;
    line.len_x = abs(line.p0.x - line.p1.x);
    line.len_y = abs(line.p0.y - line.p1.y);
    line.dx = (line.p1.x - line.p0.x) >= 0 ? 1 : -1;
    line.dy = (line.p1.y - line.p0.y) >= 0 ? 1 : -1;
    return (line);
}

