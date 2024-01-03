/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:35:01 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/03 11:52:23 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_btree.h"

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void applyf(void *));
void	btree_apply_infix(t_btree *root, void applyf(void *));
void	btree_apply_suffix(t_btree *root, void applyf(void *));

int	main(void)
{
	t_btree	*tree;

	tree = btree_create_node(5);
}
