/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:52:44 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:37:34 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*buff;

	buff = NULL;
	i = 0;
	if (min < max)
	{
		buff = malloc((max - min) * sizeof (int));
		while (i < max - min)
		{
			buff[i] = i + min;
			i++;
		}
	}
	*range = buff;
	return (i);
}
