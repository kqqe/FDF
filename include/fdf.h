/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:07:59 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/18 20:41:05 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ABS(a) (a >= 0) ? a : -a
# define MIN(a, b) a < b ? a : b
# define MAX(a, b) a > b ? a : b
# include "mlx.h"

# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;

}					t_point;

typedef struct		s_img
{
	void			*img;
	int				bts;
	int				size_line;
	int				endian;
	void			*win_ptr;
	void			*mlx_ptr;
	char			*addr;
	int				test;
}					t_img;

typedef struct		s_line
{
	t_point			p0;
	t_point			p1;
	double			len_x;
	double			len_y;
	double			dx;
	double			dy;
}					t_line;

typedef struct		s_clr
{
	int				**clr;
	int				flg;
}					t_clr;

typedef struct		s_pmtx
{
	t_point			***mtx;
	t_point			***mtx1;
	int				size_x;
	int				size_y;
	double			scope;
	double			angle;
	int				color;
	t_img			*img;
	int				**clr;
	int				**clr1;
	int				**clr2;
	int				flag;
	int				flag_button;
	int				of;
}					t_pmtx;

typedef struct		s_map
{
	struct s_map	*next;
}					t_map;

t_point				*ft_create_point(double x, double y, double z);
t_line				ft_create_line(t_point *p1, t_point *p2);
t_pmtx				*ft_create_pmtx(int size_x, int size_y);
void				zoom_plus(t_pmtx *pmtx);
void				zoom_minus(t_pmtx *pmtx);
void				ft_red_split(int **mtx, int len, char *line,
					int fd, int ret);
void				center_map(t_pmtx *pmtx);
void				rotate2(int press_key, t_pmtx *pmtx, t_point *f);
void				rotate3(int press_key, t_pmtx *pmtx, t_point *f);
void				isometry(int press_key, t_point *f);
void				save_map(t_pmtx *pmtx, t_point ***dest);
void				ft_tolya(t_pmtx *pmtx, int i, int j);
int					**ft_read_mtx(char *filename);
int					**ft_initclr(int line, int len, int **clr);
void				ft_graphics(t_pmtx *pmtx);
int					control(int press_key, void *param);
void				modul_coordinates(t_pmtx *pmtx);
void				ft_put_line(t_pmtx *mtx, t_line line, int cx, int cy);
void				draw_map(t_pmtx *mtx);
void				line_x(int i, int j, t_pmtx *mtx);
void				line_y(int i, int j, t_pmtx *mtx);
int					main_draw_function(int line_count, int len,
					t_pmtx *mtx, t_img *img);
void				ft_error_output(char *err_str);
void				menu(t_pmtx *mtx);
int					close_window(void *param);
void				arrow(int press_key, t_pmtx *pmtx);
void				rotate(int press_key, t_pmtx *pmtx);
t_pmtx				*ft_init_pmtx(int **mtx, int size_x, int size_y);
void				ft_print_pmtx(t_pmtx *pmtx);
int					check_name(char *str);
int					check_len(char *str, int k);
int					check_simbol(char *str, int k);
int					ft_color(char *str, int i);
int					check_colors(char *str, int k);
int					check_nums(char *str);
int					check_int(char *str);
int					checker(char *str);
int					pixelslen(char *av, int x);
int					validation(const int fd);
int					colorete(int z);
#endif
