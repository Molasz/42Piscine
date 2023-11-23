/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:09 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/16 17:21:34 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof (t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_list_remove_if(t_list *begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *))
{
	t_list	*prev;

	prev = ft_create_elem(NULL);
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
		{
			prev->next = begin_list->next;
			free_fct(begin_list->data);
			free(begin_list);
			begin_list = prev->next;
		}
		else
		{
			prev = begin_list;
			begin_list = begin_list->next;
		}
	}
}
