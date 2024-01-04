/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:24:35 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/04 16:03:26 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int cmpf(void *, void *))
{
	void	*res;

	if (root)
	{
		if (cmpf(root->item, data_ref))
			return (root->item);
		else
		{
			res = btree_search_item(root->right, data_ref, cmpf);
			if (res)
				return (res);
			res = btree_search_item(root->left, data_ref, cmpf);
			return (res);
		}
	}
	return (NULL);
}
