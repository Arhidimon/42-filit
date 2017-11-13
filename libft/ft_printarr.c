/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:02:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/10 19:02:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarr(char **arr)
{
	int		i;

	i = 0;
	if (!arr || !(*arr))
		ft_putstr("empty\n");
	while (arr[i])
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] => \"");
		ft_putstr(arr[i]);
		ft_putstr("\"\n");
		i++;
	}
}
