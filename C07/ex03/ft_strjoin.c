/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:28:35 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/23 17:42:05 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	k;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	k = 0;
	while (k < j)
	{
		dest[i + k] = src[k];
		k++;
	}
	return (dest);
}

void	result(char *str, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		sep_len;
	int		str_len;

	str = malloc(0);
	sep_len = ft_strlen(sep);
	str_len = 0;
	i = 0;
	while (i < size)
	{
		str_len += ft_strlen(strs[i]);
		if (i < size - 1)
			str_len += sep_len;
		i++;
	}
	if (str_len > 0)
	{
		str = (char *)malloc(str_len);
		result(str, strs, sep, size);
	}
	else
		str = (char *)malloc(1);
	return (str);
}
