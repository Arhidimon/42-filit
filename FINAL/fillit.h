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
# define ABS(Value) (Value) > 0 ? (Value) : (-Value)

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

int				validate_file(char *name, int *num_tetramino,
								t_shape *shapes);
int				save_tetramino(char *str, t_shape *shapes,
								int position);
int				ft_map_size(int num_tetramino);
char			check_collission(t_shape a, t_shape b,
						t_point pos_a, t_point pos_b);
void			printout(t_shape *shapes, t_point *positions,
				int count, int size);
void			get_solution(t_shape *shapes, t_point *positions,
					int count, int side);
char			check_collissions(t_shape *shapes, t_point *positions,
						int side, int n);
void			ft_putstr(char const *s);
#endif
