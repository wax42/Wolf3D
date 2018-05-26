/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:10:57 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 01:16:40 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_find_spawn(t_var *var)
{
	int x;
	int y;

	y = 1;
	while (++y < var->parsing.max.y - 2)
	{
		x = 1;
		while (++x < var->parsing.max.x - 2)
		{
			if (var->parsing.tab[y][x] == 1)
			{
				var->posx = x;
				var->posy = y;
				return ;
			}
		}
	}
}

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
			if (var->parsing.tab[y][x] == 0)
			{
				bol++;
				var->parsing.tab[y][x] = 1;
				var->posx = x;
				var->posy = y;
			}
		}
	}
	if (bol != 1 || (var->posx < 2 || var->posx < var->parsing.max.x) || \
	(var->posy < 2 || var->posx < var->parsing.max.x))
		ft_find_spawn(var);
}
