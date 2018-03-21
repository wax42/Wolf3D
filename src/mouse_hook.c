/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:59:47 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/19 13:43:07 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_rotate_left(t_var *var)
{
	var->r.olddirx = var->r.dirx;
	var->r.dirx = var->r.dirx * cos(var->r.rotate) - var->r.diry * \
	sin(var->r.rotate);
	var->r.diry = var->r.olddirx * sin(var->r.rotate) + var->r.diry *\
	cos(var->r.rotate);
	var->r.oldplanex = var->r.planex;
	var->r.planex = var->r.planex * cos(var->r.rotate) - var->r.planey\
	* sin(var->r.rotate);
	var->r.planey = var->r.oldplanex * sin(var->r.rotate) +\
	var->r.planey * cos(var->r.rotate);
}

void	ft_rotate_right(t_var *var)
{
	var->r.olddirx = var->r.dirx;
	var->r.dirx = var->r.dirx * cos(-var->r.rotate) - var->r.diry * \
	sin(-var->r.rotate);
	var->r.diry = var->r.olddirx * sin(-var->r.rotate) + var->r.diry * \
	cos(-var->r.rotate);
	var->r.oldplanex = var->r.planex;
	var->r.planex = var->r.planex * cos(-var->r.rotate) - var->r.planey\
	* sin(-var->r.rotate);
	var->r.planey = var->r.oldplanex * sin(-var->r.rotate) +\
	var->r.planey * cos(-var->r.rotate);
}

int		mouse_hook(int x, int y, t_var *var)
{
	y = 0;
	if (var->r.mouse == 1)
	{
		if (x > var->r.olddirx)
		{
			ft_rotate_right(var);
		}
		else
		{
			ft_rotate_left(var);
		}
	}
	var->r.olddirx = x;
	return (0);
}
