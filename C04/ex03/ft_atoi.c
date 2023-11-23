/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:05:17 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:20:52 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sum_nums(int *nums, int size)
{
	int	mult;
	int	res;
	int	i;

	i = size;
	res = 0;
	mult = 1;
	while (i >= 0)
	{
		res += nums[i] * mult;
		mult *= 10;
		i--;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				nums[10];
	int				sign;
	int				count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nums[count] = str[i] - '0';
		count++;
		i++;
	}
	return (sum_nums(nums, count - 1) * sign);
}
