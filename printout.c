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
#include <stdlib.h>
#include <unistd.h>

static void	ft_free_arr(int size, char **arr)
{
	int j;

	j = -1;
	while (++j < size)
		free(arr[j]);
	free(arr);
}

static char	**ft_set_dots(int size)
{
	int		j;
	int		i;
	char	**out;

	j = -1;
	if (!(out = (char **)malloc(sizeof(char *) * size)))
	{
		free(out);
		return (NULL);
	}
	while (++j < size)
		if (!(out[j] = (char *)malloc(sizeof(char) * size)))
		{
			ft_free_arr(j, out);
			return (NULL);
		}
	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			out[i][j] = '.';
	}
	return (out);
}

int			printout(t_shape *shapes, t_point *positions, int count, int size)
{
	int		i;
	int		j;
	char	**out;

	if (!(out = ft_set_dots(size)))
		return (-1);
	j = -1;
	while (++j < count)
	{
		i = -1;
		while (shapes[j].map[++i])
			if (shapes[j].map[i] == '1')
				out[positions[j].x + i % shapes[j].cols][positions[j].y +
						i / shapes[j].cols] = 'A' + j;
	}
	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			write(1, &out[i][j], 1);
		write(1, "\n", 1);
	}
	ft_free_arr(size, out);
	return (0);
}
