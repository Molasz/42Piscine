/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:40:32 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/04 17:05:31 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int cmpf(void *, void *))
{
	if (*root)
	{
		if (cmpf((*root)->item, item) > 0)
			btree_insert_data(&(*root)->right, item, cmpf);
		else
			btree_insert_data(&(*root)->left, item, cmpf);
	}
	else
		*root = btree_create_node(item);
}
