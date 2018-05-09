/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:59:47 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/09 04:51:34 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_rotate_left(t_var *var)
{
	var->olddirx = var->dirx;
	var->dirx = var->dirx * cos(var->rotate) - var->diry * \
	sin(var->rotate);
	var->diry = var->olddirx * sin(var->rotate) + var->diry *\
	cos(var->rotate);
	var->oldplanex = var->planex;
	var->planex = var->planex * cos(var->rotate) - var->planey\
	* sin(var->rotate);
	var->planey = var->oldplanex * sin(var->rotate) +\
	var->planey * cos(var->rotate);
}

void	ft_rotate_right(t_var *var)
{
	var->olddirx = var->dirx;
	var->dirx = var->dirx * cos(-var->rotate) - var->diry * \
	sin(-var->rotate);
	var->diry = var->olddirx * sin(-var->rotate) + var->diry * \
	cos(-var->rotate);
	var->oldplanex = var->planex;
	var->planex = var->planex * cos(-var->rotate) - var->planey\
	* sin(-var->rotate);
	var->planey = var->oldplanex * sin(-var->rotate) +\
	var->planey * cos(-var->rotate);
}

int		mouse_hook(int x, int y, t_var *var)
{
	y = 0;
	if (var->key.mouse == 1)
	{
		if (x > var->olddirx)
		{
			ft_rotate_right(var);
		}
		else
		{
			ft_rotate_left(var);
		}
	}
	var->olddirx = x;
	return (0);
}
