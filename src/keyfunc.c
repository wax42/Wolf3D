/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:48:55 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 18:11:45 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_look_left(int keycode, t_var *var)
{
	if (keycode == K_Q_LOOK_LEFT)
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

void	ft_look_right(int keycode, t_var *var)
{
	if (keycode == K_E_LOOK_RIGHT)
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

void	ft_key_commands(t_var *var, int keycode)
{
	if (keycode == 49)
		var->jump--;
	if (keycode == K_Y)
		var->del = 1;
	if (keycode == K_0)
		var->menu_select = 0;
	if (keycode == K_1)
		var->menu_select = 1;
	if (keycode == K_2)
		var->menu_select = 2;
	if (keycode == K_3)
		var->menu_select = 3;
	if (keycode == K_M)
		var->mouse = 1;
	if (keycode == K_N)
		var->mouse = 0;
	if (keycode == K_R && var->menu_select == 0)
		var->shoot += 1;
}

int		my_key_funct(int keycode, t_var *var)
{
	if (keycode == K_ESC)
		exit(1);
	ft_key_commands(var, keycode);
	ft_move_up_hook(keycode, var);
	ft_look_right(keycode, var);
	ft_look_left(keycode, var);
	return (0);
}
