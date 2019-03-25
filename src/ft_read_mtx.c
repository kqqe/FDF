/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_mtx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:45:43 by ffahey            #+#    #+#             */
/*   Updated: 2019/03/04 14:46:41 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_read_mtx(char *filename)
{
	int		**mtx;
	int		fd;
	int		ret;
	char	buffer[256];
	
	if ((fd = open(filename, O_RDONLY)) == -1)
		write(1, "error\n", 6);
	ret = read(fd, buffer, 256);
	buffer[ret] = '\0';

	
	//mtx = NULL;
	return (mtx);
}
