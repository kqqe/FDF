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

int		**ft_initclr(int line, int len, int **clr)
{
	int		i;

	i = 0;
	clr = (int**)malloc(line * sizeof(int*));
	while (i <= line)
	{
		clr[i] = (int*)malloc(len * sizeof(int));
		ft_bzero(clr[i], len);
		i++;
	}
	return (clr);
}

void	ft_graphics(int **mtx,t_pmtx *pmtx)//, int offset)
{

	t_img		*img;
	int			*addr;
	t_clr		*color;
	int			offset = 85;
	
	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->mlx_ptr = mlx_init();	
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1000, 1000, "fdF"); 
	pmtx->img = img;
	color = malloc(sizeof(t_clr));
	pmtx->clr = ft_initclr(pmtx->size_y, pmtx->size_x, pmtx->clr);
	draw_map(pmtx, 16732240);
	mlx_hook(img->win_ptr, 17, 0, close_window, (void*)0);	
	mlx_hook(img->win_ptr, 2, 0, control, (void*)(pmtx));
	mlx_loop(img->mlx_ptr);	
	free(img);
	free(pmtx->mtx);
}

void	draw_map(t_pmtx *mtx, int color)
{ 
	int 		i;
	int			j;
	t_line		linex;
	t_line		liney;

	i = 0;
	while (i < mtx->size_y)
	{
		j = 0;
		while (j < mtx->size_x)
		{
			if (j < mtx->size_x - 1)
			{	
				line_x(i, j, mtx, linex);
			}
			if (i < mtx->size_y - 1)
			{
				line_y(i, j, mtx, liney);
			}		
			j++;	
		}
		i++;
	menu(mtx);
	}
	mtx->flag = 1; 
}

void line_x(int i, int j, t_pmtx *mtx, t_line linex)
{
	linex = ft_create_line(mtx->mtx[i][j], mtx->mtx[i][j + 1]);
	if ((mtx->mtx[i][j]->z > 50 && mtx->flag == 0) || (mtx->clr[i][j] == 1))
	{
		mtx->color = 16732240;
		mtx->clr[i][j] = 1;
	}
	else 
		mtx->color = 0x0000ff00;
	ft_put_line(mtx->img->mlx_ptr, mtx->img->win_ptr, linex, mtx->color, mtx->img->addr);	
}

void line_y(int i, int j, t_pmtx *mtx, t_line liney)
{
	liney = ft_create_line(mtx->mtx[i][j], mtx->mtx[i + 1][j]);
	if ((mtx->mtx[i][j]->z > 50 && mtx->flag == 0) || (mtx->clr[i][j] == 1))
	{
		mtx->color = 16732240;
		mtx->clr[i][j] = 1;
	}
	else 
		mtx->color = 0x0000ff00;
	ft_put_line(mtx->img->mlx_ptr, mtx->img->win_ptr, liney, mtx->color, mtx->img->addr);		
}

void	menu(t_pmtx *mtx)
{
	char *string = "FDF by Pben"; 
	mlx_string_put (mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 1, 0x0000ff00, string);
}