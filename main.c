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

	positions[0].x = 0;
	positions[0].y = 0;
    tetraminos[0].rows = 2;
    tetraminos[0].cols = 3;
    tetraminos[0].map = "010111";


    if (argc != 2)
    {
        ft_putstr("usage: fillit source_file\n");
        return (0);
    }
    printf("res:%i\n", validate_file(argv[1]));
    return (0);
}