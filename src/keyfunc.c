/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:48:55 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/01 02:07:25 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int my_key_funct(int keycode, t_var *var)
{
	printf("keycode\t%d\n", keycode);
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
	{
			if(var->tab[(int)(var->d.posX + var->d.dirX * var->d.movespeed)][(int)(var->d.posY)] == 0)
		 		var->d.posX += var->d.dirX * var->d.movespeed;
			if(var->tab[(int)(var->d.posX)][(int)(var->d.posY + var->d.dirY * var->d.movespeed)] == 0)
				var->d.posY += var->d.dirY * var->d.movespeed;
	}
	if (keycode == 125)
	{
		if(var->tab[(int)(var->d.posX - var->d.dirX * var->d.movespeed)][(int)(var->d.posY)] == 0)
			var->d.posX -= var->d.dirX * var->d.movespeed;
		if(var->tab[(int)(var->d.posX)][(int)(var->d.posY - var->d.dirY * var->d.movespeed)] == 0)
			var->d.posY -= var->d.dirY * var->d.movespeed;
	}
	if (keycode == 124)
	{
		var->d.oldDirX = var->d.dirX;
		var->d.dirX = var->d.dirX * cos(-var->d.rotate) - var->d.dirY * sin(-var->d.rotate);
		var->d.dirY = var->d.oldDirX * sin(-var->d.rotate) + var->d.dirY * cos(-var->d.rotate);
		var->d.oldPlaneX = var->d.planeX;
		var->d.planeX = var->d.planeX * cos(-var->d.rotate) - var->d.planeY * sin(-var->d.rotate);
		var->d.planeY = var->d.oldPlaneX * sin(-var->d.rotate) + var->d.planeY * cos(-var->d.rotate);
	}
	if (keycode == 123)
	{
		var->d.oldDirX = var->d.dirX;
		var->d.dirX = var->d.dirX * cos(var->d.rotate) - var->d.dirY * sin(var->d.rotate);
		var->d.dirY = var->d.oldDirX * sin(var->d.rotate) + var->d.dirY * cos(var->d.rotate);
		var->d.oldPlaneX = var->d.planeX;
		var->d.planeX = var->d.planeX * cos(var->d.rotate) - var->d.planeY * sin(var->d.rotate);
		var->d.planeY = var->d.oldPlaneX * sin(var->d.rotate) + var->d.planeY * cos(var->d.rotate);
	}
	ft_raycasting(var);
	return (0);
}
