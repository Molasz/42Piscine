/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:01:14 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:31:45 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0' ))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_params(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i++ < argc - 1)
	{
		write(1, argv[i], ft_str_len(argv[i]));
		write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		check;
	char	*temp;

	i = 0;
	check = 1;
	while (check)
	{
		check = 0;
		i = 0;
		while (++i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				check = 1;
			}
		}
	}
	print_params(argc, argv);
	return (0);
}
