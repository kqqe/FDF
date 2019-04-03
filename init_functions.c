/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:44:30 by pben              #+#    #+#             */
/*   Updated: 2019/03/03 18:44:47 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pmtx    *ft_init_pmtx(int **mtx, int size_x, int size_y)
{
    t_pmtx  *pmtx;
    int i;
    int j;
    t_point ***dest;

    pmtx = ft_create_pmtx(size_x, size_y);
    pmtx->scope = 8;
    dest = pmtx->mtx;
    i = 0;
    while (i < pmtx->size_y)
    {
        j = 0;
        while (j < pmtx->size_x)
        {
            dest[i][j] = ft_create_point((j + 1) * pmtx->scope, (i + 1) * pmtx->scope, mtx[i][j]);
            j++;
        }
        i++;
    }
    return (pmtx);
}

void    ft_print_pmtx(t_pmtx *pmtx)
{
    int i;
    int j;

    printf("size_x = %d, size_y = %d\n", pmtx->size_x, pmtx->size_y);
    i = 0;
    while(i < pmtx->size_y)
    {
        j = 0;
        while(j < pmtx->size_x)
        {
            printf("(%.2f, %.2f, %.2f) ", pmtx->mtx[i][j]->x, pmtx->mtx[i][j]->y, pmtx->mtx[i][j]->z);
            j++;
        }
        printf("\n");
        i++;
    }
}