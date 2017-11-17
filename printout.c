/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:21:00 by dbezruch          #+#    #+#             */
/*   Updated: 2017/11/17 18:21:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

#include <unistd.h>

void 	printout(t_shape *shapes, t_point *positions, int count, int size)
{
	int i;
	int j;
	char	out[size][size];

	j = 0;
	while (j <size)
	{
		i = 0;
		while (i < size)
		{
			out[i][j] = '.';
			i++;
		}
		j++;
	}
	j = 0;
	while (j < count)
	{
		i = 0;
		while (shapes[j].map[i])
		{
			if (shapes[j].map[i] == '1')
				out[positions[j].x + i % shapes[j].cols][positions[j].y + i / shapes[j].cols] = 'A' + j;
			i++;
		}
		j++;
	}
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			write(1, &out[i][j], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}

}