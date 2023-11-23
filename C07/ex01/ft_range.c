/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:47:17 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:36:31 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	range = NULL;
	i = 0;
	if (min < max)
	{
		range = malloc((max - min) * sizeof (int));
		while (i < max - min)
		{
			range[i] = i + min;
			i++;
		}
	}
	return (range);
}
