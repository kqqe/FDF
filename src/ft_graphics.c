/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:38:20 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 20:52:47 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_graphics(t_pmtx *pmtx)
{
	t_img	*img;

	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1000, 1000, "fdF");
	pmtx->img = img;
	pmtx->clr = ft_initclr(pmtx->size_y, pmtx->size_x, pmtx->clr);
	pmtx->clr1 = ft_initclr(pmtx->size_y, pmtx->size_x, pmtx->clr1);
	draw_map(pmtx);
	mlx_hook(img->win_ptr, 17, 0, close_window, (void*)0);
	mlx_hook(img->win_ptr, 2, 0, control, (void*)(pmtx));
	mlx_loop(img->mlx_ptr);
	free(img);
	free(pmtx->mtx);
}

void	line_x(int i, int j, t_pmtx *mtx)
{
	t_line	linex;

	linex = ft_create_line(mtx->mtx[i][j], mtx->mtx[i][j + 1]);
	if (mtx->flag == 0)
	{
		mtx->clr[i][j] = colorete(mtx->mtx[i][j]->z);
	}
	if (mtx->flag == 0 && (mtx->mtx[i][j]->z < mtx->mtx[i][j + 1]->z))
	{
		mtx->clr[i][j] = colorete(mtx->mtx[i][j + 1]->z);
	}
	mtx->color = mtx->clr[i][j];
	ft_put_line(mtx, linex, i, j);
}

void	line_y(int i, int j, t_pmtx *mtx)
{
	t_line	liney;

	liney = ft_create_line(mtx->mtx[i][j], mtx->mtx[i + 1][j]);
	if (mtx->flag == 0)
	{
		mtx->clr1[i][j] = colorete(mtx->mtx[i][j]->z);
	}
	if (mtx->flag == 0 && (mtx->mtx[i][j]->z < mtx->mtx[i + 1][j]->z))
	{
		mtx->clr1[i][j] = colorete(mtx->mtx[i + 1][j]->z);
	}
	mtx->color = mtx->clr1[i][j];
	ft_put_line(mtx, liney, i, j);
}

void	menu(t_pmtx *mtx)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	s1 = "FDF by Pben and Adoyle";
	s2 = "Rotate button 1 - 3";
	s3 = "Zooom plus or minus";
	s4 = "Move button <- or -> or v or ^";
	s5 = "BUtton I or P or O and TAB";
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 1, 0x00FF9632, s1);
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 25, 0x00FF9632, s2);
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 50, 0x00FF9632, s3);
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 75, 0x00FF9632, s4);
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr,
	1, 100, 0x00FF9632, s5);
}
