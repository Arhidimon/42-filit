/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:55:56 by dbezruch          #+#    #+#             */
/*   Updated: 2017/11/15 16:55:58 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	check_collission(t_shape a, t_shape b, t_point pos_a, t_point pos_b)
{
	int ty;
	int tx;
	int i;
	int t;

	if (pos_a.x + a.cols <= pos_b.x || pos_b.x + b.cols <= pos_a.x ||
			pos_a.y + a.rows <= pos_b.y || pos_b.y + b.rows <= pos_a.y)
		return (0);
	i = 0;
	while (a.map[i])
	{
		if (a.map[i] == '1')
		{
			ty = i / a.cols;
			tx = i % a.cols;
			tx = tx + pos_a.x - pos_b.x;
			ty = ty + pos_a.y - pos_b.y;
			t = tx + ty * b.cols;
			if (t < b.cols * b.rows && t >= 0 && tx >= 0 && tx < b.cols &&
					ty >= 0 && ty < b.rows && b.map[t] == '1')
				return (1);
		}
		i++;
	}
	return (0);
}

char	check_collissions(t_shape *shapes, t_point *positions, int side, int n)
{
	int i;

	if (positions[n].x + shapes[n].cols > side ||
			positions[n].y + shapes[n].rows > side)
		return (1);
	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			if (check_collission(shapes[i], shapes[n],
								positions[i], positions[n]))
				return (1);
			i++;
		}
	}
	return (0);
}

int		forspace(t_shape *shapes, t_point *positions, t_point *cs, int *depth)
{
	if ((*depth >= cs->x - 1 &&
			check_collissions(shapes, positions, cs->y, cs->x - 1) == 0))
		return (2);
	if (*depth < cs->x &&
		check_collissions(shapes, positions, cs->y, *depth) == 0)
	{
		(*depth)++;
		positions[*depth].x = 0;
		positions[*depth].y = 0;
	}
	else if (*depth < cs->x)
	{
		if (*depth < 0)
			return (1);
		else if (positions[*depth].y >= cs->y)
			(*depth)--;
		positions[*depth].x++;
	}
	if (positions[*depth].x >= cs->y)
	{
		positions[*depth].x = 0;
		positions[*depth].y++;
	}
	return (0);
}

int		get_solution(t_shape *shapes, t_point *positions, int count, int side)
{
	int		depth;
	int		flag;
	t_point	cs;

	cs.x = count;
	cs.y = side;
	while (1)
	{
		flag = 0;
		depth = 0;
		positions[depth].x = 0;
		positions[depth].y = 0;
		while (flag == 0)
		{
			flag = forspace(shapes, positions, &cs, &depth);
			if (flag == 2)
				return (cs.y);
		}
		cs.y++;
	}
}
