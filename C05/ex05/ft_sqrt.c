/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:28:44 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:24:26 by molasz-a         ###   ########.fr       */
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
	return (0);
}
