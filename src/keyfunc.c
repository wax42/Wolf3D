/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:48:55 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/12 23:58:12 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int my_key_funct(int keycode, t_var *var)
{
	printf("keycode\t%d\n", keycode);
	if (keycode == K_ESC)
		exit(1);
	if(keycode == K_T)// && (var->d.posX >=19 && var->d.posX < 20) && (var->d.posY >= 9 && var->d.posY < 10))
		{
			ft_change_tex(var);
		}
	if(keycode == K_Y)
	{
		var->d.del = 1;
	}
	if (keycode == K_MOVE_UP)
	{
			// if(var->parsing. tab[(int)(var->d.posX + var->d.dirX * var->d.movespeed)][(int)(var->d.posY)] == 0)
				var->d.posX += var->d.dirX * var->d.movespeed;
			// if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY + var->d.dirY * var->d.movespeed)] == 0)
				var->d.posY += var->d.dirY * var->d.movespeed;
	}
	if (keycode == K_MOVE_DOWN)
	{
		if(var->parsing.tab[(int)(var->d.posX - var->d.dirX * var->d.movespeed)][(int)(var->d.posY)] == 0)
			var->d.posX -= var->d.dirX * var->d.movespeed;
		if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY - var->d.dirY * var->d.movespeed)] == 0)
			var->d.posY -= var->d.dirY * var->d.movespeed;
	}
	if (keycode == K_MOVE_RIGHT)
	{
		if(var->parsing.tab[(int)(var->d.posX + var->d.planeX * var->d.movespeed)][(int)(var->d.posY)] == 0)
			var->d.posX += var->d.planeX * var->d.movespeed;
		if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY + var->d.planeY * var->d.movespeed)] == 0)
			var->d.posY += var->d.planeY * var->d.movespeed;
	}
	if (keycode == K_MOVE_LEFT)
	{
		if(var->parsing.tab[(int)(var->d.posX - var->d.planeX * var->d.movespeed)][(int)(var->d.posY)] == 0)
			var->d.posX -= var->d.planeX * var->d.movespeed;
		if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY - var->d.planeY * var->d.movespeed)] == 0)
			var->d.posY -= var->d.planeY * var->d.movespeed;
	}
	if (keycode == K_LOOK_RIGHT)
	{
		var->d.oldDirX = var->d.dirX;
		var->d.dirX = var->d.dirX * cos(-var->d.rotate) - var->d.dirY * sin(-var->d.rotate);
		var->d.dirY = var->d.oldDirX * sin(-var->d.rotate) + var->d.dirY * cos(-var->d.rotate);
		var->d.oldPlaneX = var->d.planeX;
		var->d.planeX = var->d.planeX * cos(-var->d.rotate) - var->d.planeY * sin(-var->d.rotate);
		var->d.planeY = var->d.oldPlaneX * sin(-var->d.rotate) + var->d.planeY * cos(-var->d.rotate);
	}
	if (keycode == K_LOOK_LEFT)
	{
		var->d.oldDirX = var->d.dirX;
		var->d.dirX = var->d.dirX * cos(var->d.rotate) - var->d.dirY * sin(var->d.rotate);
		var->d.dirY = var->d.oldDirX * sin(var->d.rotate) + var->d.dirY * cos(var->d.rotate);
		var->d.oldPlaneX = var->d.planeX;
		var->d.planeX = var->d.planeX * cos(var->d.rotate) - var->d.planeY * sin(var->d.rotate);
		var->d.planeY = var->d.oldPlaneX * sin(var->d.rotate) + var->d.planeY * cos(var->d.rotate);
	}
	if (keycode == 126)
	{
			if(var->parsing.tab[(int)(var->d.posX + var->d.dirX * var->d.movespeed)][(int)(var->d.posY)] == 0)
		 		var->d.posX += var->d.dirX * var->d.movespeed;
			if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY + var->d.dirY * var->d.movespeed)] == 0)
				var->d.posY += var->d.dirY * var->d.movespeed;
	}
	if (keycode == 125)
	{
		if(var->parsing.tab[(int)(var->d.posX - var->d.dirX * var->d.movespeed)][(int)(var->d.posY)] == 0)
			var->d.posX -= var->d.dirX * var->d.movespeed;
		if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY - var->d.dirY * var->d.movespeed)] == 0)
			var->d.posY -= var->d.dirY * var->d.movespeed;
	}
	if (keycode == 124)
	{
		if(var->parsing.tab[(int)(var->d.posX + var->d.planeX * var->d.movespeed)][(int)(var->d.posY)] == 0)
			var->d.posX += var->d.planeX * var->d.movespeed;
		if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY + var->d.planeY * var->d.movespeed)] == 0)
			var->d.posY += var->d.planeY * var->d.movespeed;
	}
	if (keycode == 123)
	{
		if(var->parsing.tab[(int)(var->d.posX - var->d.planeX * var->d.movespeed)][(int)(var->d.posY)] == 0)
			var->d.posX -= var->d.planeX * var->d.movespeed;
		if(var->parsing.tab[(int)(var->d.posX)][(int)(var->d.posY - var->d.planeY * var->d.movespeed)] == 0)
			var->d.posY -= var->d.planeY * var->d.movespeed;
	}
	ft_raycasting(var);
	return (0);
}
