/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:13:11 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 19:47:51 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_colors(char *str, int k)
{
	int i;
	int f;

	i = 0;
	f = 0;
	while (i <= k)
	{
		if (str[i] == ',')
			f = ft_color(str, i + 1);
		if (f == 1 || (str[i] == 'x' && str[i - 2] != ','))
			return (1);
		i++;
	}
	return (0);
}

int		check_nums(char *str)
{
	int i;
	int f;

	i = 0;
	f = 0;
	while (str[i])
	{
		if ((str[i] > 64 && str[i] < 71) || (str[i] > 96 && str[i] < 103))
		{
			if (str[i - 1] && str[i - 2] && str[i - 3] && str[i - 4] &&
				str[i - 5] && str[i - 6] && str[i - 7])
			{
				if (str[i - 1] != 'x' && str[i - 2] != 'x' &&
				str[i - 3] != 'x' && str[i - 4] != 'x' && str[i - 5] != 'x' &&
					str[i - 6] != 'x' && str[i - 7] != 'x' && str[i - 8] != 'x')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int		check_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] > 47 && str[i + 1] < 58))
		{
			if (str[i + 2] && (str[i + 2] > 47 &&
				str[i + 2] < 58) && ft_atoi(str + i + 1) < 0)
				return (1);
		}
		if (str[i] == ' ' && str[i + 1] == '-' &&
			(str[i + 2] > 47 && str[i + 2] < 58))
		{
			if (str[i + 3] && (str[i + 3] > 47 && str[i + 3] < 58) &&
				(ft_atoi(str + i + 1) >= 0))
				return (1);
		}
		i++;
	}
	return (0);
}

int		checker(char *str)
{
	int			i;
	static int	len;
	int			k;

	i = 0;
	if (str[0] == '\n' || str[1] == '\0')
		return (0);
	k = ft_strlen(str);
	if (len == 0)
		len = check_len(str, k);
	i = check_len(str, k);
	if (i != len || i == 0 || (str[0] < 47 && str[0] > 58))
		return (1);
	if (check_simbol(str, k) == 1 || check_colors(str, k) == 1 ||
		check_nums(str) == 1 || check_int(str) == 1)
		return (1);
	return (0);
}

int		validation(const int fd)
{
	char	*line;
	int		f;
	int		l;

	f = 0;
	l = 1;
	while (l > 0)
	{
		l = get_next_line(fd, &line);
		if (l > 0)
			f = checker(line);
		if (f == 1)
			return (1);
	}
	close(fd);
	return (0);
}
