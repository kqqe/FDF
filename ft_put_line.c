/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:15:27 by ffahey            #+#    #+#             */
/*   Updated: 2019/03/04 14:30:42 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line_by_x(void *mlx_ptr, void *win_ptr, t_line line, int colour, char *s)
{
	double		x;
	double		y;
	double		d;
	double		len;
	int		*addr;
	int 	size_window_picture = 500;

	len = MAX(line.len_x, line.len_y) + 1;
	x = line.p0.x;
	y = line.p0.y;
	d = -line.len_x;
	while (len--)
	{
		addr = (int*)s;
		addr[((int)(x + (y * size_window_picture))) - 1] = colour; //к инту привести
		x += line.dx;
		d += 2 * line.len_y;
		if (d > 0)
		{
			d -= 2 * line.len_x;
			y += line.dy;
		}
	}

}

static void	line_by_y(void *mlx_ptr, void *win_ptr, t_line line, int colour, char *s)
{
	double		x;
	double		y;
	double		d;
	double		len;
	int		*addr;
	int 	size_window_picture = 500;

	len = MAX(line.len_x, line.len_y) + 1;
	x = line.p0.x;
	y = line.p0.y;
	d = -line.len_y;
	while (len--)
	{	
		addr = (int*)s;
		addr[((int)(x + (y * size_window_picture))) - 1] = colour;// приводить к double онли тут 
		y += line.dy;
		d += 2 * line.len_x;
		if (d > 0)
		{
			d -= 2 * line.len_y;
			x += line.dx;
		}
	}
}

void		ft_put_line(void *mlx_ptr, void *win_ptr, t_line line, int colour, char *s)
{
	if (line.len_y <= line.len_x)
		line_by_x(mlx_ptr, win_ptr, line, colour, s);
	else
		line_by_y(mlx_ptr, win_ptr, line, colour, s);
}
