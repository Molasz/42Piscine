/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:51:11 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/19 12:27:36 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

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
