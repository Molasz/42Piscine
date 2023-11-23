/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:52:24 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 16:47:50 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 1;
	while (str[i] != '\0')
	{
		if (tmp && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if (!tmp && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9')))
			tmp = 1;
		else
			tmp = 0;
		i++;
	}
	return (str);
}
