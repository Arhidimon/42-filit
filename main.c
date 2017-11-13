/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:16:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/13 15:16:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr("usage: fillit source_file\n");
        return (0);
    }
    printf("res:%i\n", check_file(argv[1]));
    return (0);
}