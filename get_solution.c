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

t_point	set_point(char x, char y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

char	check_collission(t_shape a, t_shape b, t_point pos_a, t_point pos_b)
{
	int ty;
	int tx;
    int i;
    int t;
	t_point dp;

	if (pos_a.x + a.cols <= pos_b.x || pos_b.x + b.cols <= pos_a.x || pos_a.y + a.rows <= pos_b.y || pos_b.y + b.rows <= pos_a.y)
		return (0);
    i = 0;
    while (a.map[i])
    {
        if (a.map[i] == '1')
        {
            ty = i / a.cols;
            tx = i % a.cols;
			//if (pos_a.x >= pos_b.x)
			//	t = (pos_a.y >= pos_b.y)?tx + pos_a.x - pos_b.x + (ty + pos_a.y - pos_b.y) * b.cols:tx + pos_a.x - pos_b.x + (ty -pos_a.y + pos_b.y) * b.cols;
			//else
			//	t = (pos_a.y >= pos_b.y)?tx - pos_a.x + pos_b.x + (ty + pos_a.y - pos_b.y) * b.cols:tx - pos_a.x + pos_b.x + (ty -pos_a.y + pos_b.y) * b.cols;
			t = tx + pos_a.x - pos_b.x + (ty + pos_a.y - pos_b.y) * b.cols;
			//ft_putnbr(i);
			//ft_putchar(':');
			//ft_putnbr(t);
			//ft_putchar('\n');
            if ( t < b.cols * b.rows && b.map[t] == '1')
                return (1);
        }
        i++;
    }
	return (0);
}

char	check_collissions(t_shape *shapes, t_point *positions, int side, int n)
{
	int i;

	if (positions[n].x + shapes[n].cols > side || positions[n].y + shapes[n].rows > side)
		return (1);
	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			if (check_collission(shapes[i], shapes[n], positions[i], positions[n]))
				return (1);
			i++;
		}
	}
	return (0);
}

int 	get_solution(t_shape *shapes, t_point *positions, int count, int side)
{
	int depth;
	int x;
	int y;
	int flag;

	flag = 0;
	while (flag != 2)
	{
		flag = 0;
		depth = 0;
		positions[depth].x = 0;
		positions[depth].y = 0;
		while (flag == 0) {
			if (positions[0].y == side)
				flag = 0;
			if ((depth == count - 1 && check_collissions(shapes, positions, side, depth) == 0))
				flag = 2;
			if (positions[depth].x == side - 1)
			{
				positions[depth].x = 0;
				positions[depth].y++;
			}
			if (depth < count && check_collissions(shapes, positions, side, depth) == 0)
			{
				depth++;
				positions[depth].x = 0;
				positions[depth].y = 0;
			}
			else if (depth < count)
			{
				if (depth < 0)
					flag = 1;
				else if (positions[depth].y == side)
					depth--;
				positions[depth].x++;
			}
		}
		side++;
	}
	return (side - 1);
}
