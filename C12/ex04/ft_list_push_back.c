/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42Barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 00:59:10 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/14 01:12:22 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*last_list;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (*begin_list)
	{
		last_list = ft_list_last(*begin_list);
		last_list->next = elem;
	}
	else
		*begin_list = elem;
}
