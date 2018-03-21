/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:10:57 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 16:22:37 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_pos_spawn_check(t_var *var, int x, int y)
{
	if ((x == 0 || y == 0) && (x == var->parsing.max.x || \
											y == var->parsing.max.y))
	{
		if (var->parsing.tab[x][y] != 2)
			ft_exit(0);
	}
}

void	ft_pos_spawn(t_var *var)
{
	int x;
	int y;
	int bol;

	x = -1;
	bol = 0;
	while (++x < var->parsing.max.x)
	{
		y = -1;
		while (++y < var->parsing.max.y)
		{
			if (var->parsing.tab[x][y] == 0)
			{
				bol++;
				var->parsing.tab[x][y] = 1;
				var->r.posx = x;
				var->r.posy = y;
			}
			ft_pos_spawn_check(var, x, y);
		}
	}
	if (bol != 1)
		ft_exit(0);
}
