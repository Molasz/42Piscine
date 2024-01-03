/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:58:53 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/02 13:18:47 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	tree = malloc(sizeof(t_btree));
	if (!tree)
		return (NULL);
	tree->item = item;
	tree->left = 0;
	tree->right = 0;
	return (tree);
}
