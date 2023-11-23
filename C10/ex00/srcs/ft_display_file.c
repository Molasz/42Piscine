/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:06:45 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/04 15:47:17 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		f;
	char	c;

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		f = open(argv[1], O_RDONLY);
		if (f < 0)
			write(2, "Cannot read file.\n", 18);
		else
		{
			while (read(f, &c, 1))
				write(1, &c, 1);
			close(f);
		}
		return (0);
	}
}
