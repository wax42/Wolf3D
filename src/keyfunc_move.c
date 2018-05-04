/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 03:07:26 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/04 19:06:41 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_move_left_hook(int keycode, t_var *var)
{
	double cal_y;
	double cal_x;

	cal_x = var->r.planex * var->r.movespeed;
	cal_y = var->r.planey * var->r.movespeed;
	if ((int)(var->r.posx - cal_x) < var->parsing.max.x && (int)\
					(var->r.posx - cal_x) > 0 && var->parsing.max.y > (int)\
						(var->r.posy - cal_y) && 0 < (int)(var->r.posy - cal_y))
	{
		if (keycode == K_A_MOVE_LEFT || keycode == K_ARROW_LEFT)
		{
			if (var->parsing.tab[(int)(var->r.posy - cal_y)][(int)\
															(var->r.posx)] == 1)
				var->r.posy -= cal_y;
			if (var->parsing.tab[(int)(var->r.posy)][(int)(var->r.posx - \
										cal_x)] == 1)
				var->r.posx -= cal_x;
		}
	}
}

void	ft_move_right_hook(int keycode, t_var *var)
{
	double cal_y;
	double cal_x;

	if (keycode == K_D_MOVE_RIGHT || keycode == K_ARROW_RIGHT)
	{
		cal_x = var->r.planex * var->r.movespeed;
		cal_y = var->r.planey * var->r.movespeed;
		if ((int)(var->r.posx + cal_x) < var->parsing.max.x && (int)\
					(var->r.posx + cal_x) > 0 && var->parsing.max.y > (int)\
						(var->r.posy + cal_y) && 0 < (int)(var->r.posy + cal_y))
		{
			if (var->parsing.tab[(int)(var->r.posy + cal_y)][(int)\
															(var->r.posx)] == 1)
				var->r.posy += cal_y;
			if (var->parsing.tab[(int)(var->r.posy)][(int)(var->r.posx + \
										cal_x)] == 1)
				var->r.posx += cal_x;
		}
	}
	ft_move_left_hook(keycode, var);
}

void	ft_move_down_hook(int keycode, t_var *var)
{
	double cal_y;
	double cal_x;

	if (keycode == K_S_MOVE_DOWN || keycode == K_ARROW_DOWM)
	{
		cal_x = var->r.dirx * var->r.movespeed;
		cal_y = var->r.diry * var->r.movespeed;
		if ((int)(var->r.posx - cal_x) < var->parsing.max.x && (int)\
		(var->r.posx - cal_x) > 0 && var->parsing.max.y > (int)\
						(var->r.posy - cal_y) && 0 < (int)(var->r.posy - cal_y))
		{
			if (var->parsing.tab[(int)(var->r.posy - \
				cal_y)][(int)(var->r.posx)] == 1)
				var->r.posy -= cal_y;
			if (var->parsing.tab[(int)(var->r.posy)][(int)\
				(var->r.posx - cal_x)] == 1)
				var->r.posx -= cal_x;
		}
	}
	ft_move_right_hook(keycode, var);
}

void	ft_move_up_hook(int keycode, t_var *var)
{
	double cal_y;
	double cal_x;

	if (keycode == K_W_MOVE_UP || keycode == K_ARROW_UP)
	{
		cal_x = var->r.dirx * var->r.movespeed;
		cal_y = var->r.diry * var->r.movespeed;
		if ((int)(var->r.posx + cal_x) < var->parsing.max.x && (int)\
					(var->r.posx + cal_x) > 0 && var->parsing.max.y > (int)\
						(var->r.posy + cal_y) && 0 < (int)(var->r.posy + cal_y))
		{
			if (var->parsing.tab[(int)(var->r.posy + cal_y)][(int)\
															(var->r.posx)] == 1)
				var->r.posy += cal_y;
			if (var->parsing.tab[(int)(var->r.posy)][(int)(var->r.posx + \
										cal_x)] == 1)
				var->r.posx += cal_x;
		}
	}
	ft_move_down_hook(keycode, var);
}
