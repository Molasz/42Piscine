/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:18:36 by molasz-a          #+#    #+#             */
/*   Updated: 2023/10/26 18:27:42 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = 0;
	result = nb;
	while (i < power - 1)
	{
		result *= nb;
		i++;
	}
	return (result);
}
