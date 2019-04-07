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
	//img->img = mlx_new_image(img->mlx_ptr, WINDOW, WINDOW);// картинки в окне
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1000, 1000, "fdF"); //ширина, длина окна
	//img->addr = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);

	pmtx->img = img;
	draw_map(line_count, len, pmtx, 0x0000ff00);

	char *string = "FDF by Pben"; 
	mlx_string_put (img->mlx_ptr, img->win_ptr, 1, 1, 0x0000ff00, string);

	mlx_hook(img->win_ptr, 17, 0, close_window, (void*)0);	
	mlx_hook(img->win_ptr, 2, 0, control, (void*)(pmtx));
	mlx_loop(img->mlx_ptr);	
	//free(img);
	//free(pmtx->mtx);
}

void	draw_map(int line_count, int len, t_pmtx *mtx, int color)
{ 
	int 		i;
	int			j;
	t_line		linex;
	t_line		liney;

	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (j < len)
		{
			if (j < len - 1)
			{	
				linex = ft_create_line(mtx->mtx[i][j], mtx->mtx[i][j + 1]);
				 ft_put_line(mtx->img->mlx_ptr, mtx->img->win_ptr, linex, color, mtx->img->addr);	
			}
			if (i < line_count - 1)
			{
				liney = ft_create_line(mtx->mtx[i][j], mtx->mtx[i + 1][j]);
				ft_put_line(mtx->img->mlx_ptr, mtx->img->win_ptr, liney, color, mtx->img->addr);		
			}		
			//mlx_put_image_to_window(mtx->img->mlx_ptr, mtx->img->win_ptr, mtx->img->img, 50, 50);// c какого пикселя вставлять в окно
			j++;	
		}
		i++;
	}
}
