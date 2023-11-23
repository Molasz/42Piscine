/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:58:29 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/19 13:11:56 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (*begin_list)
		elem->next = *begin_list;
	*begin_list = elem;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	int		*elem;
	int		sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		list = *begin_list;
		while (list->next)
		{
			if (cmp(list->data, list->next->data) > 0)
			{
				elem = list->data;
				list->data = list->next->data;
				list->next->data = elem;
				sorted = 0;
			}
			list = list->next;
		}
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sort(begin_list, cmp);
}
