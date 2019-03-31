/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben	<marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:39:35 by pben              #+#    #+#             */
/*   Updated: 2019/03/04 14:58:17 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		close_window(void *param)
{
	exit(-2);
	return (0);
}

void	ft_graphics(int **mtx, int line_count, int len)//, int offset)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	linex, liney;
	t_img	*img;
	char	*s;
	int		*addr;
	int 	offset = 20;
	int		scope = 30;


	mlx_ptr = mlx_init();
	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->img = mlx_new_image(mlx_ptr, 500, 500);// картинки в окне
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdF"); //ширина, длина окна
	s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
	int i = 0;
	int j = 0;
	int  z;
	while (i < line_count )
	{
		j = 0;
		while (j < len)
		{
			if (j < len - 1)
			{
				linex = ft_create_line(ft_create_point((j + 1)  * scope, (i + 1) * scope, mtx[i][j]),
								ft_create_point((j + 2) * scope, (i + 1) * scope, mtx[i][j + 1])); 
				ft_put_line(mlx_ptr, win_ptr, linex, 0x0000ff00, s);
				
			}
			if (i < line_count - 1)
			{
				liney = ft_create_line(ft_create_point((j + 1) * scope, (i + 1) * scope, mtx[i][j]),
								ft_create_point((j + 1)  * scope, (i + 2) * scope, mtx[i + 1][j]));	
				ft_put_line(mlx_ptr, win_ptr, liney, 0x0000ff00, s);
				
			}		
			mlx_put_image_to_window(mlx_ptr, win_ptr, img->img,	offset, offset);// c какого пикселя вставлять в окно
			j++;	
		}
		i++;
	}
	char *string = "FDF by Pben"; 
	mlx_string_put (mlx_ptr, win_ptr, 0, 0, 0x0000ff00, string);
	mlx_hook (win_ptr, 17, 0, close_window, (void*)0);
	mlx_hook(win_ptr, 2, 0, key_pressed, (void*)0);
	mlx_loop(mlx_ptr);
}

void 		control(int press_key, t_point *f)
{
	
	if (press_key == 13);//движение фигуры назад w
	{ 
		f->angle+=1; 
		f->x = f->x * cos(f->angle) + f->z * sin(f->angle);
	 	f->y = f->y;
		f->z = - f->x * sin(f->angle) + f->z * cos(f->angle);
	}
	if (press_key == 1);// на себя s 
	{
		f->angle+=1; 
		f->x = f->x * cos(f->angle) + f->z * sin(f->angle);
		f->y = f->y;
		f->z = - f->x * sin(f->angle) + f->z * cos(f->angle);
	}
	if (press_key == 0);//left a
	{
		f->angle+=1; 
		f->x = f->x; 
		f->y = f->y * cos(f->angle) + f->z * sin(f->angle);
		f->z = -f->y * sin(f->angle) + f->z * cos(f->angle);
	}
	if (press_key == 2);//right d
	{
		f->angle+=1; 
		f->x = f->x; 
		f->y = f->y * cos(f->angle) + f->z * sin(f->angle);
		f->z = -f->y * sin(f->angle) + f->z * cos(f->angle);
	}
}

int	key_pressed(int key, void *param)
{

}
// }

// void	move_map(t_point f, int i, int j)
// {
// 	double 	angle;
// 	int		x;
// 	int		y;
// 	int		z;

// 	x = f.x;
// 	y = f.y;
// 	z = f.z;
// 	//rotation x
// 	f.x = x; 
// 	f.y = y * cos(angle) + z * sin(angle);
// 	f.z = -y * sin(angle) + z * cos(angle);
// 	// rotate y 
// 	f.x = x * cos(angle) + z * sin(angle);
// 	f.y = y;
// 	f.z = - x * sin(angle) + z * cos(angle);
// 	// rotate z
// 	f.x = x * cos(angle) + z * sin(angle);
// 	f.y = x * sin(angle) + y * cos(angle);
// 	f.z = z;

// }
