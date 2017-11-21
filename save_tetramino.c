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

void	cut_tetramino_horisontal(char *str, t_shape *shape)
{
	int		col;
	int		row;
	int		sharp;
	int		len;

	len = 0;
	row = -1;
	while (++row <= 3)
	{
		col = -1;
		sharp = 0;
		while (++col <= 3)
			if (str[row * 5 + col] == '#')
				sharp++;
		len = (sharp > 0) ? ++len : len;
		if (sharp == 0)
			while (--col >= 0)
				str[row * 5 + col] = '*';
	}
	shape->rows = len;
}

void	cut_tetramino_vertical(char *str, t_shape *shape)
{
	int		col;
	int		row;
	int		sharp;
	int		len;

	len = 0;
	col = -1;
	while (++col <= 3)
	{
		row = -1;
		sharp = 0;
		while (++row <= 3)
			if (str[col + row * 5] == '#')
				sharp++;
		len = (sharp > 0) ? ++len : len;
		if (sharp == 0)
			while (--row >= 0)
				str[col + row * 5] = '*';
	}
	shape->cols = len;
}

int		save_tetramino(char *str, t_shape *shapes, int pos)
{
	int		len;
	int		i;

	cut_tetramino_vertical(str, &(shapes[pos]));
	cut_tetramino_horisontal(str, &(shapes[pos]));
	len = 0;
	i = -1;
	while (++i < 20)
		if (str[i] == '#' || str[i] == '.')
			len++;
	if (!(shapes[pos].map = (char *)malloc(sizeof(char) * (len + 1))))
		return (1);
	*(shapes[pos].map + len) = '\0';
	while (--i >= 0)
		if (str[i] == '#')
			(shapes[pos].map[--len]) = '1';
		else if (str[i] == '.')
			(shapes[pos].map[--len]) = '0';
	return (0);
}
