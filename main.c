/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:16:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/13 15:16:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
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
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	if (validate_file(argv[1], &num_tetramino, &tetraminos[0]))
	{
		ft_free_all(&tetraminos[0], num_tetramino);
		ft_putstr("error\n");
		return (0);
	}
	map_size = ft_map_size(num_tetramino);
	map_size = get_solution(tetraminos, positions, num_tetramino, map_size);
	if (printout(tetraminos, positions, num_tetramino, map_size) == -1)
		ft_putstr("error\n");
	ft_free_all(&tetraminos[0], num_tetramino);
	return (0);
}
