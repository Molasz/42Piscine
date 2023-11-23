/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:52:15 by molasz-a          #+#    #+#             */
/*   Updated: 2023/10/21 14:32:17 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	assigns(int *i, int *temp_pos);

void	initials(int *i, int *small, int *temp_pos, int*tab);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	small;
	int	temp_val;
	int	temp_pos;

	initials(&i, &small, &temp_pos, tab);
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[j] < small)
			{
				small = tab[j];
				temp_pos = j;
			}
			j++;
		}
		temp_val = tab[i];
		tab[i] = small;
		tab[temp_pos] = temp_val;
		assigns(&i, &temp_pos);
		small = tab[i];
	}
}

void	initials(int *i, int *small, int *temp_pos, int *tab)
{
	*i = 0;
	*small = tab[0];
	*temp_pos = 0;
}

void	assigns(int *i, int *temp_pos)
{
	*i = *i + 1;
	*temp_pos = *i;
}
