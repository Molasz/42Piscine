/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:30:46 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:25:03 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;
	long int	lp;
	long int	rp;

	lp = 0;
	rp = nb;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (rp - lp > 1)
	{
		i = (rp + lp) / 2;
		if (i * i == nb)
			return (i);
		else if (i * i > nb)
			rp = i;
		else
			lp = i;
	}
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	max;

	i = 2;
	if (nb < 2)
		return (0);
	max = ft_sqrt(nb);
	while (i <= max)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
