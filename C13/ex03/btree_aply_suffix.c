/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_aply_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:29:55 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/03 11:32:02 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void applyf(void *))
{
	if (root)
	{
		btree_apply_suffix(root->right, applyf);
		btree_apply_suffix(root->left, applyf);
		applyf(root->item);
	}
}
