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

t_point ft_create_point(int **mtx, int line_count, int len)
{
    t_point     point;

    // point.x = x;
    // point.y = y;
    // point.z = z;
    int     i;
    int     j;

    i = 0;
    while (i < line_count )
    {
        j = 0;
        while(j < len )
        {
            if(mtx[i][j] == 0)
            {
                point.x = j;
                point.y = i;
            }
            else
                point.z = 0; //mtx[i][j]; - так должно быть
        } 
    }
    return (point);
}

t_line  ft_create_line(t_point p1, t_point p2)
{
    t_line  line;

    line.p0 = p1;
    line.p1 = p2;
    line.len_x = ABS(line.p0.x - line.p1.x);
    line.len_y = ABS(line.p0.y - line.p1.y);
    line.dx = (line.p1.x - line.p0.x) >= 0 ? 1 : -1;
    line.dy = (line.p1.y - line.p0.y) >= 0 ? 1 : -1;
    return (line);
}

