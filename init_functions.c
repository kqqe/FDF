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
    int offset = 50;

    pmtx = ft_create_pmtx(size_x, size_y);
    dest = pmtx->mtx;
    i = 0;
    while (i < pmtx->size_y)
    {
        j = 0;
        while (j < pmtx->size_x)
        {
            dest[i][j] = ft_create_point((j + 1) + offset, (i + 1) + offset, mtx[i][j] + offset);
            j++;
        }
        i++;
    }
    //ft_print_pmtx(pmtx);
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

void    zoom_plus(t_pmtx *pmtx)
{
    t_point diff;
    int i;
    int j;

    i = 0;
    if (i == 0 && j == 0)
        diff = *(pmtx->mtx[0][0]);
    while (i < pmtx->size_y)
    {
        j = 0;
        while (j < pmtx->size_x)
        {
            pmtx->mtx[i][j]->x *= pmtx->scope;
            pmtx->mtx[i][j]->x -= diff.x;
            pmtx->mtx[i][j]->y *= pmtx->scope;
            pmtx->mtx[i][j]->y -= diff.y;
            j++;
        }
        i++;
    }
}
void    zoom_minus(t_pmtx *pmtx)
{
    t_point diff;
    int i;
    int j;
    
    i = 0;
    if (i == 0 && j == 0)
        diff = *(pmtx->mtx[0][0]);
    while (i < pmtx->size_y)
    {
        j = 0;
        while (j < pmtx->size_x)
        {
            pmtx->mtx[i][j]->x += diff.x;
            pmtx->mtx[i][j]->x /= pmtx->scope;
            pmtx->mtx[i][j]->y += diff.y;
            pmtx->mtx[i][j]->y /= pmtx->scope;
           j++;
        }
        i++;
    }
}