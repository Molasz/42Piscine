/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:31:16 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/04 18:05:38 by molasz-a         ###   ########.fr       */
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

void	check_level(t_btree *root, int current_level, int *levels,
		void applyf(void *item, int current_level, int is_first_elem))
{
	int	is_first;

	is_first = 1;
	if (levels[current_level] == 1)
		is_first = 1;
	else
		levels[current_level] = 1;
	applyf(root->left, current_level, is_first);
	if (root->left)
		check_level(root->left, current_level + 1, levels, applyf);
	if (root->right)
		check_level(root->right, current_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root,
		void applyf(void *item, int current_level, int is_first_elem))
{
	int	*levels;
	int	levels_count;
	int	i;

	if (root)
	{
		levels_count = btree_level_count(root);
		levels = malloc(levels_count * sizeof(int));
		if (!levels)
			return ;
		i = 0;
		while (i < levels_count)
			levels[i++] = 0;
		check_level(root, 0, levels, applyf);
	}
}
