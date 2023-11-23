/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:04 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/09 15:38:25 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_ten_queens_puzzle_check(int board[10], int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (y == board[i] || i + board[i] == x + y || i - board[i] == x - y)
			return (0);
		i++;
	}
	return (1);
}

void	ft_ten_queens_puzzle_resovle(int board[10], int *res, int pos)
{
	int	i;
	int	j;

	if (pos == 10)
	{
		*res += 1;
		j = -1;
		while (++j < 10)
			ft_putchar(board[j] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			if (ft_ten_queens_puzzle_check(board, pos, i))
			{
				board[pos] = i;
				ft_ten_queens_puzzle_resovle(board, res, pos + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	res;

	i = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}
	res = 0;
	ft_ten_queens_puzzle_resovle(board, &res, 0);
	return (res);
}
