/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:04:50 by molasz-a          #+#    #+#             */
/*   Updated: 2023/10/26 10:53:24 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		ft_str_len(char *str);
int		ft_check_duplicated(char *str);
void	ft_putnbr_base(int nb, char *base);
void	i_base(int nbr, int base, char *chars);

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (ft_check_duplicated(base))
		return ;
	base_len = ft_str_len(base);
	if (base_len < 2)
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		i_base(nbr / -base_len, base_len, base);
		ft_putchar(base[nbr % base_len * -1]);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		i_base(-nbr, base_len, base);
	}
	else
		i_base(nbr, base_len, base);
}

void	i_base(int nbr, int base, char *chars)
{
	if (nbr < base)
	{
		ft_putchar(chars[nbr % base]);
	}
	else
	{
		i_base(nbr / base, base, chars);
		ft_putchar(chars[nbr % base]);
	}
}

int	ft_check_duplicated(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (str[i])
	{
		j = 0;
		count = 0;
		if (!(str[i] >= 32 && str[i] <= 126) || str[i] == '+' || str[i] == '-' )
			return (1);
		while (str[j])
		{
			if (str[j] == str[i])
				count++;
			j++;
		}
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
