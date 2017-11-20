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

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
    t_shape tetraminos[26];
	t_point positions[26];
	int 	num_tetramino;
	int 	map_size;

    tetraminos[0].rows = 2;
    tetraminos[0].cols = 2;
    tetraminos[0].map = "1111";
	tetraminos[1].rows = 2;
	tetraminos[1].cols = 2;
	tetraminos[1].map = "1111";
	tetraminos[2].rows = 2;
	tetraminos[2].cols = 2;
	tetraminos[2].map = "1111";
	tetraminos[3].rows = 2;
	tetraminos[3].cols = 2;
	tetraminos[3].map = "1111";
	tetraminos[4].rows = 2;
	tetraminos[4].cols = 2;
	tetraminos[4].map = "1111";

	positions[0].x = 0;
	positions[0].y = 0;
	positions[1].x = 2;
	positions[1].y = 0;
	positions[2].x = 0;
	positions[2].y = 2;
	positions[3].x = 2;
	positions[3].y = 2;
	positions[4].x = 2;
	positions[4].y = 3;

	printf("Collisions:%i\n",check_collissions(tetraminos, positions, 7, 4));
/*    if (argc != 2)
    {
        ft_putstr("usage: fillit source_file\n");
        return (0);
    }*/
    printf("res:%i\n", validate_file(argv[1], &num_tetramino, tetraminos));
	num_tetramino = 5;
    map_size = ft_map_size(num_tetramino);
    printf("Number of tetromisnos:%i\nMap size:%i\n",num_tetramino, map_size);
	get_solution(tetraminos, positions, num_tetramino, map_size);
	printf("1 (%i,%i)  3(%i,%i) coll %i\n",positions[0].x,positions[0].y,positions[4].x,positions[4].y, check_collission(tetraminos[0],tetraminos[4],positions[0],positions[4]));
	//printout(tetraminos, positions, 5, 8);
    return (0);
}