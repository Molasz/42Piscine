/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:55:35 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 16:49:27 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned char	strval;
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		strval = (unsigned char)str[i];
		if (str[i] < ' ' || str[i] > '~')
		{
			ft_putchar('\\');
			ft_putchar(hex[strval / 16]);
			ft_putchar(hex[strval % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
