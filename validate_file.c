/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:25:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/13 20:25:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include <stdio.h>
#include "libft/libft.h"

int		num_of_connections(char *str, int i)
{
	int		connection;

	connection = 0;
	if (i + 1 < 20 && str[i + 1] == '#')
		connection++;
	if (i - 1 >= 0 && str[i - 1] == '#')
		connection++;
	if (i + 5 < 20 && str[i + 5] == '#')
		connection++;
	if (i - 5 >= 0 && str[i - 5] == '#')
		connection++;
	return (connection);
}

int		valid_map(char *str, int size, int *tetramino)
{
	int		i;
	int		sharp;
	int		connections;

	//ft_putstr("valid map\n");
	if ((size == 21 && str[20] != '\n') || (size == 20 && str[19] != '\n'))
		return (1);
	i = 0;
	sharp = 0;
	connections = 0;
	while (i < 20)
	{
		if ((i % 5 == 4 && str[i] != '\n') ||
			(i % 5 != 4 && str[i] != '.' && str[i] != '#'))
			return (2);
		if (str[i] == '#')
		{
			sharp++;
			connections += num_of_connections(str, i);
		}
		i++;
	}

	if (sharp != 4 || connections < 6)
		return (3);
	 *tetramino += 1;
	//ft_putstr("end valid map\n");
	return (0);
}

int		validate_file(char *name, int *num_tetramino, t_shape *shapes)
{
	int		fd;
	char	buff[21];
	int		num;
	int		last_line;
	int		i;


	if (!(fd = open(name, O_RDONLY)))
		return (-1);
	i = 0;
	while ((num = read(fd, buff, 21)))
	{
		if (valid_map(buff, num, num_tetramino) != 0)
		{
			close(fd);
			return (2);
		}
		last_line = num;
		//ft_putstr("ok\n");
		save_tetramino(buff, shapes, *num_tetramino - 1);

	}
	if (*num_tetramino == 0 || *num_tetramino > 26 || last_line != 20)
		return (3);
	close(fd);
	return (0);
}
