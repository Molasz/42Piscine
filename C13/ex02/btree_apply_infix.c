/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:23:41 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/03 11:26:29 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void applyf(void *))
{
	if (root)
	{
		btree_apply_infix(root->right, applyf);
		applyf(root->item);
		btree_apply_infix(root->left, applyf);
	}
}
