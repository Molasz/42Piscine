/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42Barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:53:41 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/14 13:11:57 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*list;
	t_list	*next;

	i = 0;
	next = NULL;
	while (i < size)
	{
		list = ft_create_elem(strs[i]);
		if (!list)
			return (NULL);
		list->next = next;
		next = list;
		i++;
	}
	return (list);
}
