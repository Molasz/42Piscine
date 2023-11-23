/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:21:53 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 16:15:42 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char a1, char a2, char *b1, char *b2)
{
	while (*b1 <= '9')
	{
		while (*b2 <= '9')
		{
			if (!(a1 == '9' && a2 == '9'))
			{
				write(1, &a1, 1);
				write(1, &a2, 1);
				write(1, " ", 1);
				write(1, b1, 1);
				write(1, b2, 1);
				if (!(a1 == '9' && a2 == '8' && *b1 == '9' && *b2 == '9'))
					write(1, ", ", 2);
			}
			*b2 += 1;
		}
		*b1 += 1;
		*b2 = '0';
	}
}

void	assign(char *a1, char *a2, char *b1, char *b2)
{
	*a1 += 1;
	*a2 = '0';
	*b1 = *a1;
	*b2 = *a2 + 1;
}

void	init_values(char *a1, char *a2, char *b1, char *b2)
{
	*a1 = '0';
	*a2 = '0';
	*b1 = '0';
	*b2 = '1';
}

void	ft_print_comb2(void)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	init_values(&a1, &a2, &b1, &b2);
	while (a1 <= '9')
	{
		while (a2 <= '9')
		{
			print(a1, a2, &b1, &b2);
			a2++;
			if (a2 == '9')
			{
				b1 = a1 + 1;
				b2 = '0';
			}
			else
			{
				b1 = a1;
				b2 = a2 + 1;
			}
		}
		assign(&a1, &a2, &b1, &b2);
	}
}
