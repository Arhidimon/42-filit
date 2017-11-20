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

	if (ABS(pos_a.x - pos_b.x) > 4 || ABS(pos_a.y - pos_b.y) > 4)
		return 0;
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
            if (tx >= 0 && ty >= 0 && t < b.cols * b.rows && b.map[t] == '1')
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

void 	get_solution(t_shape *shapes, t_point *positions, int count, int side)
{
	int depth;
	int maxside;
	int x;
	int y;


	maxside = side + 2;
	while (side <= maxside + 1)
	{


		depth = 0;
		positions[depth].x = 0;
		positions[depth].y = 0;




		while (depth < count +1 && positions[0].y < side)
		{

			if (check_collissions(shapes, positions, side, depth) == 0)
			{

				ft_putnbr(depth);
				ft_putchar('\n');
				ft_putnbr(check_collissions(shapes, positions, side, depth));
				ft_putchar('\n');
				ft_putnbr(positions[depth].x);
				ft_putchar(',');
				ft_putnbr(positions[depth].y);
				ft_putchar('\n');
				printout(shapes, positions, depth+1, side);

				depth++;
				positions[depth].x = 0;
				positions[depth].y = 0;
			}
			else
				positions[depth].x++;
			if (positions[depth].x == side)
			{
				positions[depth].y++;
				positions[depth].x = 0;
			}
			if (positions[depth].y == side && depth != 0)
			{
				depth--;
				positions[depth].x++;
			}
			if (positions[depth].x == side)
			{
				positions[depth].y++;
				x = 0;
			}


		}

		if (depth == count)
		{
			printout(shapes, positions, count, side);
			return;
		}
		side++;
	}


}
