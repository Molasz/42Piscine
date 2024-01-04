/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:50:59 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/04 16:51:03 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	right;
	int	left;

	right = 0;
	left = 0;
	if (root)
	{
		if (root->right)
		{
			right++;
			right += btree_level_count(root->right);
		}
		else
		{
			left++;
			left += btree_level_count(root->left);
		}
		if (right > left)
			return (right);
		else
			return (left);
	}
	return (0);
}
