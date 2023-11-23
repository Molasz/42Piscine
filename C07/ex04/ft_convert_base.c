/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:36 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:46:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_check_base(char *c);

void	ft_revstr(char *tab, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = temp;
		i++;
	}
}

char	*calc_result(char *base_to, int to_len, int num)
{
	int		i;
	char	*str;
	int		sign;

	sign = 1;
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	str = (char *)malloc(100 * 4);
	i = 0;
	while (num != 0)
	{
		str[i] = base_to[num % to_len];
		num /= to_len;
		i++;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	ft_revstr(str, i);
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		to_len;

	to_len = ft_check_base(base_to);
	num = ft_atoi_base(nbr, base_from);
	if (to_len < 2 || num == -1)
		return (NULL);
	else
		return (calc_result(base_to, to_len, num));
}
