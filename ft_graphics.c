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

void	ft_graphics(int **mtx, int line_count, int len, t_pmtx *pmtx)//, int offset)
{

	t_img	*img;
	int		*addr;
	int 	offset = 85;

	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->mlx_ptr = mlx_init();	
	img->img = mlx_new_image(img->mlx_ptr, 500, 500);// картинки в окне
	img->win_ptr = mlx_new_window(img->mlx_ptr, 500, 500, "fdF"); //ширина, длина окна
	img->addr = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
	draw_map(line_count, len,pmtx, img);
	char *string = "FDF by Pben"; 
	mlx_string_put (img->mlx_ptr, img->win_ptr, 1, 1, 0x0000ff00, string);
	mlx_hook (img->win_ptr, 17, 0, close_window, (void*)0);	
	mlx_hook(img->win_ptr, 2, 0, control, (void*)(img->connect));
	mlx_loop(img->mlx_ptr);
}

void	draw_map(int line_count, int len, t_pmtx *mtx, t_img *img)
{ 
	int 		i;
	int			j;
	t_line		linex;
	t_line		liney;

	i = 0;
	while (i < line_count )
	{
		j = 0;
		while (j < len)
		{
			if (j < len - 1)
			{	
				linex = ft_create_line(ft_create_point((j + 1) * mtx->scope, (i + 1) * mtx->scope, mtx->mtx[i][j]->z),
								ft_create_point((j + 2) * mtx->scope, (i + 1) * mtx->scope, mtx->mtx[i][j + 1]->z));
				 ft_put_line(img->mlx_ptr, img->win_ptr, linex, 0x0000ff00, img->addr);	
			}
			if (i < line_count - 1)
			{
				liney = ft_create_line(ft_create_point((j + 1) * mtx->scope, (i + 1) * mtx->scope, mtx->mtx[i][j]->z),
								ft_create_point((j + 1)  * mtx->scope, (i + 2) * mtx->scope, 0));	
				ft_put_line(img->mlx_ptr, img->win_ptr, liney, 0x0000ff00, img->addr);
				
			}		
			mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 50, 50);// c какого пикселя вставлять в окно
			j++;	
		}
		i++;
	}
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
