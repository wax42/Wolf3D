/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:48:55 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 14:43:25 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_look_left(int keycode, t_var *var)
{
	if (keycode == K_Q_LOOK_LEFT)
	{
		var->r.olddirx = var->r.dirx;
		var->r.dirx = var->r.dirx * cos(var->r.rotate) - var->r.diry * \
															sin(var->r.rotate);
		var->r.diry = var->r.olddirx * sin(var->r.rotate) + var->r.diry * \
															cos(var->r.rotate);
		var->r.oldplanex = var->r.planex;
		var->r.planex = var->r.planex * cos(var->r.rotate) - var->r.planey * \
															sin(var->r.rotate);
		var->r.planey = var->r.oldplanex * sin(var->r.rotate) + var->r.planey *\
															cos(var->r.rotate);
	}
}

void	ft_look_right(int keycode, t_var *var)
{
	if (keycode == K_E_LOOK_RIGHT)
	{
		var->r.olddirx = var->r.dirx;
		var->r.dirx = var->r.dirx * cos(-var->r.rotate) - var->r.diry * \
															sin(-var->r.rotate);
		var->r.diry = var->r.olddirx * sin(-var->r.rotate) + var->r.diry * \
															cos(-var->r.rotate);
		var->r.oldplanex = var->r.planex;
		var->r.planex = var->r.planex * cos(-var->r.rotate) - var->r.planey * \
															sin(-var->r.rotate);
		var->r.planey = var->r.oldplanex * sin(-var->r.rotate) + var->r.planey \
														* cos(-var->r.rotate);
	}
}

void	ft_key_commands(t_var *var, int keycode)
{
	if (keycode == K_Y)
		var->r.del = 1;
	if (keycode == K_0)
		var->r.menu_select = 0;
	if (keycode == K_1)
		var->r.menu_select = 1;
	if (keycode == K_2)
		var->r.menu_select = 2;
	if (keycode == K_3)
		var->r.menu_select = 3;
	if (keycode == K_M)
		var->r.mouse = 1;
	if (keycode == K_N)
		var->r.mouse = 0;
	if (keycode == K_R && var->r.menu_select == 0)
		var->r.shoot += 1;
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
