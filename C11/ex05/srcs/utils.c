/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:33:32 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/06 14:03:05 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			nb = nb % 10;
		}
		if (nb < 10)
			ft_putchar(nb + 48);
	}
}

void	check_numbers(char *str, int *i, int *nums, int *result)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nums[*result] = str[*i] - '0';
		*result += 1;
		*i += 1;
	}
}

int	sum_numbers(int count, int *nums)
{
	int	i;
	int	result;
	int	mult;

	i = count;
	result = 0;
	mult = 1;
	while (i >= 0)
	{
		result += nums[i] * mult;
		mult *= 10;
		i --;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	count;
	int	nums[100];

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	check_numbers(str, &i, nums, &count);
	return (sum_numbers(count - 1, nums) * sign);
}
