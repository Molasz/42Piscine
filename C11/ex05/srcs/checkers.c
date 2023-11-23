/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:35:12 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/06 15:31:41 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	check_sign(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*'
			|| str[0] == '/' || str[0] == '%'))
		return (str[0]);
	return (0);
}
