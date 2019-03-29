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

void	ft_graphics(int **mtx, int line_count, int len)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	linex, liney;
	t_img	*img;
	char	*s;
	int		*addr;
	int 	offset = 50;
	int		scope = 50;


	mlx_ptr = mlx_init();
	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->img = mlx_new_image(mlx_ptr, 500, 500);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdF"); //ширина, длина окна
	s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
	int i = 0;
	int j;
	while (i < line_count)
	{
		j = 0;
		while (j < len - 1)
		{
			linex = ft_create_line(ft_create_point(j * scope, i * scope),
							ft_create_point((j + 1) * scope, i * scope));
			ft_put_line(mlx_ptr, win_ptr, linex, 0x0000ff00, s);
			if (i < line_count - 1)
			{
				liney = ft_create_line(ft_create_point(j * scope, i * scope),
								ft_create_point(j * scope, (i + 1) * scope));	
				ft_put_line(mlx_ptr, win_ptr, liney, 0x0000ff00, s);
			}		
			mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 50, 50);// c какого пикселя вставлять в окно
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}
