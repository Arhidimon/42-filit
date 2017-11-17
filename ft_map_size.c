/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:34:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/15 17:34:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_map_size(int num_tetramino)
{
	int		size;

	size = 2;
	while (size * size < num_tetramino * 4)
		size++;
	return (size);
}