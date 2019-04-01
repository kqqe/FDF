/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:50:14 by ffahey            #+#    #+#             */
/*   Updated: 2019/03/04 14:56:36 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_output(char *err_str)
{
	int		len;

	len = ft_strlen(err_str);
	write(2, err_str, len);
	exit(1);
}

int		close_window(void *param)
{
	exit(-2);
	return (0);
}
