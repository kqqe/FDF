/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:34:21 by pben              #+#    #+#             */
/*   Updated: 2019/03/04 14:55:58 by pben	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ABS(a) (a >= 0) ? a : -a
# define MIN(a, b) a < b ? a : b
# define MAX(a, b) a > b ? a : b
# define WINDOW 900
# include "mlx.h"

# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
#include <stdlib.h>
# include "X.h"

# define C(a) printf("check%d\n", a);
# define USAGE "Usage: ./fdf [map file]\n"

typedef struct  s_point
{
	double		x;
	double		y;
	double		z;
	double		angle;
	double		scope;
}               t_point;
// system variable
typedef struct	s_img
{
	void		*img;
	int			bts;
	int			size_line;
	int			endian;
	void		*win_ptr;
	void		*mlx_ptr;
	char		*addr;
	int 		test;
}             	t_img;

typedef struct  s_line
{
	t_point		p0;
	t_point		p1;
	double		len_x;
	double		len_y;
	double		dx;
	double		dy;
}               t_line;

typedef struct	s_pmtx
{
	t_point		***mtx;
	int			size_x;
	int			size_y;
	double		scope;
	double		angle;
	int			color;
	t_img		*img;
	int			flag;
}               t_pmtx;

typedef struct		s_map
{
	struct s_map	*next;
}					t_map;


//Creating functions
t_point         *ft_create_point(double, double, double);
t_line          ft_create_line(t_point *p1, t_point *p2);
t_pmtx          *ft_create_pmtx(int size_x, int size_y);
void		    zoom_plus(t_pmtx *pmtx);
void    		zoom_minus(t_pmtx *pmtx);
//General functions
int				**ft_read_mtx(char *filename);
void			ft_graphics(int **mtx, int line_count, int len, t_pmtx *pmtx);
int				control(int press_key, void *param);
void 			modul_coordinates(t_pmtx *pmtx);
//Draw functions
void			ft_put_line(void *mlx_p, void *win_p, t_line line, int colour, char *s);
void			draw_map(int line_count, int len, t_pmtx *mtx, int color);
int				main_draw_function(int line_count, int len, t_pmtx *mtx, t_img *img);
void			ft_error_output(char *err_str);
//system function
int				close_window(void *param);
// control function 
void 			arrow(int press_key, t_pmtx *pmtx);
void			rotate(int press_key, t_pmtx *pmtx);
//ffahey write this functions!
t_pmtx    *ft_init_pmtx(int **mtx, int size_x, int size_y);
void    ft_print_pmtx(t_pmtx *pmtx);

#endif
