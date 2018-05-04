/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:10:57 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/04 19:44:19 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_pos_spawn(t_var *var)
{
	int x;
	int y;
	int bol;

	y = -1;
	bol = 0;
	while (++y < var->parsing.max.y)
	{
		x = -1;
		while (++x < var->parsing.max.x)
		{
			ft_putnbr(var->parsing.tab[y][x]);
			if (var->parsing.tab[y][x] == 0)
			{
				bol++;
				var->parsing.tab[y][x] = 1;
				var->r.posx = x;
				var->r.posy = y;
			}
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	if (bol != 1)
		ft_exit(1);
}
