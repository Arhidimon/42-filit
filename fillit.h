/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:24:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/13 15:24:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H


# define ABS(Value) Value>0?Value:-Value

/* I straight   polyomino		1 4  1111
 *								4 1  1111
 *
 * O    square  polyomino		2 2  1111
 *
 * T			T-polyomino		2 3  111010
 * 								2 3  010111
 * 								3 2  101110
 * 								3 2  011101
 *
 * J							3 2  111010
 * 								3 2  010111
 * 								2 3  100111
 * 								2 3  111100
 *
 * L							2 3  001111
 * 								2 3  111100
 * 								3 2  101011
 * 								3 2  110101
 *
 * S							2 3  011110
 * 								3 2  101101
 *
 * Z							2 3  110011
 * 								3 2  011110
 */


typedef struct	s_shape
{
	char		rows;
	char		cols;
	char		*map;
}				t_shape;

typedef struct	s_point
{
	char		x;
	char		y;
}				t_point;

int				validate_file(char *name, int *num_tetramino);
t_shape			*save_tetramino(char * str);

#endif