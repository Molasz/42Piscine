/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:40:32 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/04 01:40:49 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int cmpf(void *, void *))
{
	t_btree	*branch;

	if (*root)
	{
		branch = *root;
		if (cmpf(branch->item, item) > 0)
			branch = branch->left;
		else
			branch = branch->right;
		btree_insert_data(&branch->right, branch->item, cmpf);
		branch->item = item;
	}
}
