/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 03:35:21 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 01:15:50 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_cal_img_width(t_var *var)
{
	var->o.spritewidth = abs((int)(WIN_X / var->o.transformy)) / UDIV;
	var->o.drawstartx = -var->o.spritewidth / 2 + var->o.spritescreenx;
	if (var->o.drawstartx < 0)
		var->o.drawstartx = 0;
	var->o.drawendx = var->o.spritewidth / 2 + var->o.spritescreenx;
	if (var->o.drawendx >= WIN_X)
		var->o.drawendx = WIN_X - 1;
}

void	ft_cal_img_height(t_var *var)
{
	var->o.drawstarty = -var->o.spriteheight / 2 + WIN_Y / 2 + \
	var->vmovescreen;
	if (var->o.drawstarty < 0)
		var->o.drawstarty = 0;
	var->o.drawendy = var->o.spriteheight / 2 + WIN_Y / 2 + var->vmovescreen;
	if (var->o.drawendy >= WIN_Y)
		var->o.drawendy = WIN_Y - 1;
}

void	ft_init_obj(t_var *var, int x, int y)
{
	double indev;
	double spritex;
	double spritey;

	var->o.coord.x = x;
	var->o.coord.y = y;
	spritex = (double)(x) + 0.4 - var->posx;
	spritey = (double)(y) + 0.4 - var->posy;
	indev = 1.0 / (var->planex * var->diry - var->dirx * var->planey);
	var->o.transformx = indev * \
	(var->diry * spritex - var->dirx * spritey);
	var->o.transformy = indev * \
	(-var->planey * spritex + var->planex * spritey);
	var->o.spritescreenx = (int)((WIN_X / 2) * \
	(1 + var->o.transformx / var->o.transformy));
	var->vmovescreen = (int)(VMOVE / var->o.transformy);
	var->o.spriteheight = abs((int)(WIN_Y / var->o.transformy)) / VDIV;
	ft_cal_img_height(var);
	ft_cal_img_width(var);
	var->o.bol = 1;
}
