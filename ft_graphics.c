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

void	ft_graphics(int **mtx, int line_count, int len)//, int offset)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	linex, liney;
	t_img	*img;
	char	*s;
	int		*addr;
	int 	offset = 85;
	double		scope = 20;


	mlx_ptr = mlx_init();
	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->img = mlx_new_image(mlx_ptr, 500, 500);// картинки в окне
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdF"); //ширина, длина окна
	s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
	double i = 0;
	double j = 0;
	img->connect = ft_create_point(0,0,0);
	while (i < line_count )
	{
		j = 0;
		while (j < len)
		{
			if (j < len - 1)
			{
				linex = ft_create_line(ft_create_point((j + 1)  * scope, (i + 1) * scope, mtx[(int)i][(int)j]),
								ft_create_point((j + 2) * scope, (i + 1) * scope, mtx[(int)i][(int)j + 1])); 
				ft_put_line(mlx_ptr, win_ptr, linex, 0x0000ff00, s);
				
			}
			if (i < line_count - 1)
			{
				liney = ft_create_line(ft_create_point((j + 1) * scope, (i + 1) * scope, mtx[(int)i][(int)j]),
								ft_create_point((j + 1)  * scope, (i + 2) * scope, mtx[(int)i + 1][(int)j]));	
				ft_put_line(mlx_ptr, win_ptr, liney, 0x0000ff00, s);
				
			}		
			mlx_put_image_to_window(mlx_ptr, win_ptr, img->img,	offset, offset);// c какого пикселя вставлять в окно
			j++;	
		}
		i++;
	}
	char *string = "FDF by Pben"; 
	mlx_string_put (mlx_ptr, win_ptr, 600, 20, 0x0000ff00, string);
	mlx_hook (win_ptr, 17, 0, close_window, (void*)0);
	
	mlx_hook(win_ptr, 2, 0, control, (void*)(img->connect));
	mlx_loop(mlx_ptr);
}

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
