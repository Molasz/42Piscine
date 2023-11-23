/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:31:14 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/19 12:56:21 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	int		i;
	int		j;
	int		size;
	void	*tmp;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size - 1)
	{
		j = i;
		current = begin_list;
		while (current && current->next && j < size - 1)
		{
			tmp = current->data;
			current->data = current->next->data;
			current->next->data = tmp;
			current = current->next;
			j++;
		}
		i++;
	}
}
