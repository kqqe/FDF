/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valchecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:24:39 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/17 17:30:26 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_len(char *str, int k)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i <= k)
	{
		if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\0') &&
			str[i - 1] != ' ')
			count++;
		i++;
	}
	return (count + 1);
}

int		check_simbol(char *str, int k)
{
	int		i;

	i = k - 1;
	while (i > 0)
	{
		if (str[i] == ' ' || str[i] == 'x' || (str[i] == '-' &&
			(str[i + 1] > 47 && str[i + 1] < 58)) ||
			str[i] == ',' || (str[i] > 47 && str[i] < 58) ||
			(str[i] > 64 && str[i] < 71) || (str[i] > 96 && str[i] < 103))
			i--;
		else
			return (1);
	}
	return (0);
}

int		ft_color(char *str, int i)
{
	if (str[i] != '0' || str[i + 1] != 'x' || str[i - 1] != ',')
		return (1);
	i = i + 2;
	while (str[i] && str[i] != ' ')
	{
		if ((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 71)
			|| (str[i] > 96 && str[i] < 103))
			i++;
		else
			return (1);
	}
	return (0);
}
