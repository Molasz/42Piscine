/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:31:07 by molasz-a          #+#    #+#             */
/*   Updated: 2023/10/30 15:10:01 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi_base(char *str, char *base);
int		ft_val_base(char c, char *base);
int		ft_check_repr(char *base);
char	*ft_get_sign(int *sign, char *str);

int	ft_val_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_base(char *base)
{
	int	l_base;
	int	n;

	n = 1;
	l_base = 0;
	while (base[l_base] != '\0')
	{
		if (base[l_base] == '+' || base[l_base] == '-' || base[l_base] == ' '
			|| !(base[l_base] > 31 && base[l_base] < 127))
			return (-1);
		n = 1;
		while (base[l_base + n] != '\0')
		{
			if (base[l_base + n] == base[l_base])
				return (-1);
			n++;
		}
		l_base++;
	}
	return (l_base);
}

int	ft_atoi_base(char *str, char *base)
{
	int	l_base;
	int	res;
	int	val_unit;
	int	sign;

	res = 0;
	sign = 1;
	l_base = ft_check_base(base);
	if (l_base < 2)
		return (0);
	str = ft_get_sign(&sign, str);
	while (*str)
	{
		val_unit = ft_val_base(*str, base);
		if (val_unit == -1)
			break ;
		res = l_base * res + val_unit;
		str++;
	}
	return (res * sign);
}

char	*ft_get_sign(int *sign, char *str)
{
	while ((*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v') && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str == '-')
			*sign = *sign * -1;
		str++;
	}
	return (str);
}
