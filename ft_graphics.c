/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:38:20 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 19:53:29 by pben             ###   ########.fr       */
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

void	ft_graphics(int **mtx, t_pmtx *pmtx)
{
	t_img	*img;
	int		*addr;
	t_clr	*color;

	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1000, 1000, "fdF");
	pmtx->img = img;
	color = malloc(sizeof(t_clr));
	pmtx->clr = ft_initclr(pmtx->size_y, pmtx->size_x, pmtx->clr);
	pmtx->clr1 = ft_initclr(pmtx->size_y, pmtx->size_x, pmtx->clr1);
	draw_map(pmtx, 16732240);
	mlx_hook(img->win_ptr, 17, 0, close_window, (void*)0);
	mlx_hook(img->win_ptr, 2, 0, control, (void*)(pmtx));
	mlx_loop(img->mlx_ptr);
	free(img);
	free(pmtx->mtx);
}

int		colorete(int z)
{
	int			color;

	if (z == 325)
		color = 65280;
	else if (z < 0)
		color = 0x0008080 + (z * 3 * (-1));
	else
		color = 0x0008080 + (z * 3);
	return (color);
}

void	draws(t_pmtx *mtx, int i, int j)
{
	mtx->clr[i][j] = colorete(mtx->mtx[i][j]->z);
	mtx->color = mtx->clr[i][j];
}

void	draws1(t_pmtx *mtx, int i, int j)
{
	mtx->clr1[i][j] = colorete(mtx->mtx[i][j]->z);
	mtx->color = mtx->clr1[i][j];
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
			if (j < mtx->size_x && mtx->flag == 0)
				draws(mtx, i, j);
			if (j < mtx->size_x - 1)
				line_x(i, j, mtx, linex);
			if (i < mtx->size_y && mtx->flag == 0)
				draws1(mtx, i, j);
			if (i < mtx->size_y - 1)
				line_y(i, j, mtx, liney);	
			j++;	
		}
		i++;	
	}
	menu(mtx);
	mtx->flag = 1; 
}

void line_x(int i, int j, t_pmtx *mtx, t_line linex)
{
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

void line_y(int i, int j, t_pmtx *mtx, t_line liney)
{	
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
	s3 = "(.).!.(.)";
	s4 = "Move button <- or -> or v or ^";
	s5 = "BUtton I or P or O and TAB";
	
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 1, 0x00FF9632, s1);
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 25, 0x00FF9632, s2);
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 50, 0x00FF9632, s3);
	mlx_string_put(mtx->img->mlx_ptr, mtx->img->win_ptr, 1, 75, 0x00FF9632, s4);
	mlx_string_put(mtx->img->mlx_ptr,
	 mtx->img->win_ptr, 1, 100, 0x00FF9632, s5);
}
