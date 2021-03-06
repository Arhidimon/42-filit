/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:16:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/28 17:02:53 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_free_all(t_shape *tetraminos, int num)
{
	while (num-- > 0)
	{
		free((tetraminos[num].map));
	}
}

int			main(int argc, char **argv)
{
	t_shape	tetraminos[26];
	t_point	positions[26];
	int		num_tetramino;
	int		map_size;

	num_tetramino = 0;
	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	if (validate_file(argv[1], &num_tetramino, &tetraminos[0]))
	{
		ft_free_all(&tetraminos[0], num_tetramino);
		write(1, "error\n", 6);
		return (0);
	}
	map_size = ft_map_size(num_tetramino);
	map_size = get_solution(tetraminos, positions, num_tetramino, map_size);
	if (printout(tetraminos, positions, num_tetramino, map_size) == -1)
		write(1, "error\n", 6);
	ft_free_all(&tetraminos[0], num_tetramino);
	return (0);
}
