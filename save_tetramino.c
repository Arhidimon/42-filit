/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tetramino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:29:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/14 16:29:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

char		*cut_tetramino(char *str, t_shape *list)
{
	int 	height;
	int 	row_len;
	int 	row;
	int 	column;
	int 	col_height;

	column = -1;
	row_len = 0;
	height = 0;
	while (++column <= 3)
	{
		row = -1;
		col_height = 0;
		while (++row <= 3)
		{
			if (str[column + row * 5] == '#')
			{
				col_height++;
				row_len++;
				break;
			}
			height = (col_height > height) ? col_height : height;
		}

	}
	list->cols = row_len;
	list->rows = height;
	row = -1;
	row_len = 0;


	printf("row_len: %i\n\n", row_len);
	return (NULL);
}

int		save_tetramino(char *str)
{
	//int 	row_len;

	cut_tetramino(str);
	return (1);
}