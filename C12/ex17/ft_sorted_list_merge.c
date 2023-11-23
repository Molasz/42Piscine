/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:13:15 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/19 13:33:35 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list	*last;

	last = *begin_list;
	while (last->next)
		last = last->next;
	last->next = begin_list2;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list*begin_list2,
		int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
