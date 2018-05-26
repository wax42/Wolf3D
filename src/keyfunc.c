/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:48:55 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/11 14:43:06 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_look_left(t_var *var)
{
	if (var->key.look_left == 1)
	{
		var->olddirx = var->dirx;
		var->dirx = var->dirx * cos(var->rotate) - var->diry * \
															sin(var->rotate);
		var->diry = var->olddirx * sin(var->rotate) + var->diry * \
															cos(var->rotate);
		var->oldplanex = var->planex;
		var->planex = var->planex * cos(var->rotate) - var->planey * \
															sin(var->rotate);
		var->planey = var->oldplanex * sin(var->rotate) + var->planey *\
															cos(var->rotate);
	}
}

void	ft_look_right(t_var *var)
{
	if (var->key.look_right == 1)
	{
		var->olddirx = var->dirx;
		var->dirx = var->dirx * cos(-var->rotate) - var->diry * \
															sin(-var->rotate);
		var->diry = var->olddirx * sin(-var->rotate) + var->diry * \
															cos(-var->rotate);
		var->oldplanex = var->planex;
		var->planex = var->planex * cos(-var->rotate) - var->planey * \
															sin(-var->rotate);
		var->planey = var->oldplanex * sin(-var->rotate) + var->planey \
														* cos(-var->rotate);
	}
}

void	ft_key_event(t_var *var)
{
	ft_look_right(var);
	ft_look_left(var);
	ft_move_up_hook(var);
}
