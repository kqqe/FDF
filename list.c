/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:25:35 by pben              #+#    #+#             */
/*   Updated: 2019/03/28 14:25:38 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*list_new(char **mtx)
{
	t_map *head;

	head = (t_map*)malloc(sizeof(t_map));
	head->mtx = mtx;
	head->next = NULL;
	return (head);
}

void	list_add_tail(t_map **head, char **mtx)
{
	while (*head != NULL)
		head = &((*head)->next);
	*head = list_new(mtx);
}

void	free_list(t_list **head)
{
	t_map	*tmp;
	size_t	i;

	while (*head)
	{
		tmp = (*head)->next;
		i = 0;
		while ((*head)->mtx[i] != NULL)
		{
			free((*head)->mtx[i]);
			i++;
		}
		free((*head)->mtx);
		free(*head);
		*head = tmp;
	}
}
