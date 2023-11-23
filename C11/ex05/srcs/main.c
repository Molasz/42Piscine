/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:27:43 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/06 17:05:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str);
int	check_sign(char *str);
int	calc(int val1, int val2, char sign);

int	main(int argc, char **argv)
{
	int		value1;
	int		value2;
	char	sign;

	if (argc == 4)
	{
		value1 = ft_atoi(argv[1]);
		value2 = ft_atoi(argv[3]);
		sign = check_sign(argv[2]);
		if (!sign)
		{
			write(1, "0\n", 2);
			return (0);
		}
		if (calc(value1, value2, sign))
		{
			if (sign == '/')
				write(1, "Stop : division by zero\n", 24);
			else
				write(1, "Stop : modulo by zero\n", 22);
		}
		else
			write(1, "\n", 1);
	}
	return (0);
}
