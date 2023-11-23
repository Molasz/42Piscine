/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:44:33 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/06 15:31:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int n);
int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

int	calc_divmod(int val2, char sign, int *operation)
{
	if (val2 == 0)
		return (1);
	if (sign == '/')
		*operation = 3;
	else
		*operation = 4;
	return (0);
}

int	calc(int val1, int val2, char sign)
{
	int	operation;
	int	number;
	int	(*operators[5])(int, int);

	operators[0] = add;
	operators[1] = sub;
	operators[2] = mul;
	operators[3] = div;
	operators[4] = mod;
	if (sign == '+')
		operation = 0;
	else if (sign == '-')
		operation = 1;
	else if (sign == '*')
		operation = 2;
	else
	{
		if (calc_divmod(val2, sign, &operation))
			return (1);
	}
	number = operators[operation](val1, val2);
	ft_putnbr(number);
	return (0);
}
