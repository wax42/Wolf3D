/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 03:07:26 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/11 13:19:33 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_move_left_hook(t_var *var)
{
	double cal_y;
	double cal_x;

	cal_x = var->planex * var->movespeed;
	cal_y = var->planey * var->movespeed;
	if (var->key.left == 1)
	{
		if ((int)(var->posx - cal_x) < var->parsing.max.x && (int)\
						(var->posx - cal_x) > 0 && var->parsing.max.y > (int)\
							(var->posy - cal_y) && 0 < (int)(var->posy - cal_y))
		{
			if (var->parsing.tab[(int)(var->posy - cal_y)][(int)\
															(var->posx)] == 1)
				var->posy -= cal_y;
			if (var->parsing.tab[(int)(var->posy)][(int)(var->posx - \
										cal_x)] == 1)
				var->posx -= cal_x;
		}
	}
}

void	ft_move_right_hook(t_var *var)
{
	double cal_y;
	double cal_x;

	if (var->key.right == 1)
	{
		cal_x = var->planex * var->movespeed;
		cal_y = var->planey * var->movespeed;
		if ((int)(var->posx + cal_x) < var->parsing.max.x && (int)\
					(var->posx + cal_x) > 0 && var->parsing.max.y > (int)\
						(var->posy + cal_y) && 0 < (int)(var->posy + cal_y))
		{
			if (var->parsing.tab[(int)(var->posy + cal_y)][(int)\
															(var->posx)] == 1)
				var->posy += cal_y;
			if (var->parsing.tab[(int)(var->posy)][(int)(var->posx + \
										cal_x)] == 1)
				var->posx += cal_x;
		}
	}
	ft_move_left_hook(var);
}

void	ft_move_down_hook(t_var *var)
{
	double cal_y;
	double cal_x;

	if (var->key.down == 1)
	{
		cal_x = var->dirx * var->movespeed;
		cal_y = var->diry * var->movespeed;
		if ((int)(var->posx - cal_x) < var->parsing.max.x && (int)\
		(var->posx - cal_x) > 0 && var->parsing.max.y > (int)\
						(var->posy - cal_y) && 0 < (int)(var->posy - cal_y))
		{
			if (var->parsing.tab[(int)(var->posy - \
				cal_y)][(int)(var->posx)] == 1)
				var->posy -= cal_y;
			if (var->parsing.tab[(int)(var->posy)][(int)\
				(var->posx - cal_x)] == 1)
				var->posx -= cal_x;
		}
	}
	ft_move_right_hook(var);
}

void	ft_move_up_hook(t_var *var)
{
	double cal_y;
	double cal_x;

	if (var->key.up == 1)
	{
		cal_x = var->dirx * var->movespeed;
		cal_y = var->diry * var->movespeed;
		if ((int)(var->posx + cal_x) < var->parsing.max.x && (int)\
					(var->posx + cal_x) > 0 && var->parsing.max.y > (int)\
						(var->posy + cal_y) && 0 < (int)(var->posy + cal_y))
		{
			if (var->parsing.tab[(int)(var->posy + cal_y)][(int)\
															(var->posx)] == 1)
				var->posy += cal_y;
			if (var->parsing.tab[(int)(var->posy)][(int)(var->posx + \
										cal_x)] == 1)
				var->posx += cal_x;
		}
	}
	ft_move_down_hook(var);
}
