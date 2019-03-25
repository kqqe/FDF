/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:39:35 by ffahey            #+#    #+#             */
/*   Updated: 2019/03/04 14:58:17 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_graphics(int **mtx)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	line;
	t_img	*img;
	char	*s;
	int		*addr;


	mlx_ptr = mlx_init();
	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->img = mlx_new_image(mlx_ptr, 500, 500);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdF"); //ширина, длина окна
	s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
	line = ft_create_line(ft_create_point(400, 200, 0),
						ft_create_point(100, 150, 0));
	ft_put_line(mlx_ptr, win_ptr, line, 0x0000ff00, s);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 50, 50);// c какого пикселя вставлять в окно
	mlx_loop(mlx_ptr);
}
