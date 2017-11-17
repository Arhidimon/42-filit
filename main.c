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


/*    if (argc != 2)
    {
        ft_putstr("usage: fillit source_file\n");
        return (0);
    }*/
    //printf("res:%i\n", validate_file(argv[1], &num_tetramino, tetraminos));
	num_tetramino = 5;
    map_size = ft_map_size(num_tetramino);
    printf("Number of tetromisnos:%i\nMap size:%i\n",num_tetramino, map_size);
	get_solution(tetraminos, positions, num_tetramino, map_size);
	printf("x1 %i y1 %i x2 %i y2 %icoll %i\n",positions[0].x,positions[0].y,positions[2].x,positions[2].y, check_collission(tetraminos[0],tetraminos[2],positions[0],positions[2]));
	//printout(tetraminos, positions, 2, 8);
    return (0);
}