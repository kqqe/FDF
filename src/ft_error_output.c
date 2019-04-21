/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:37:26 by pben              #+#    #+#             */
/*   Updated: 2019/04/18 20:21:36 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error_output(char *err_str)
{
	int		len;

	len = ft_strlen(err_str);
	write(2, err_str, len);
	exit(1);
}

int			close_window(void *param)
{
	if (param != NULL)
		exit(-2);
	return (0);
}
