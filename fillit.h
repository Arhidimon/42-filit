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

/* I straight   polyomino    1 4  1111
 *4 1  1111
 *      square  polyomino
 * T   T-polyomino 2 3 111010
 */

int		check_file(char *name);

typedef struct  s_shape
{
    char    rows;
    char    cols;
    char    *map;
}               t_shape;

#endif