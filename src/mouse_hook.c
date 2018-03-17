/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:59:47 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/17 12:38:02 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int                mouse_hook(int x, int y, t_var *var)
{
    y = 0;
	if(var->d.mouse == 1)
	{
    	if (x > var->d.oldDirX)
	    {
			var->d.oldDirX = var->d.dirX;
			var->d.dirX = var->d.dirX * cos(-var->d.rotate) - var->d.dirY * sin(-var->d.rotate);
			var->d.dirY = var->d.oldDirX * sin(-var->d.rotate) + var->d.dirY * cos(-var->d.rotate);
			var->d.oldPlaneX = var->d.planeX;
			var->d.planeX = var->d.planeX * cos(-var->d.rotate) - var->d.planeY * sin(-var->d.rotate);
			var->d.planeY = var->d.oldPlaneX * sin(-var->d.rotate) + var->d.planeY * cos(-var->d.rotate);
	    }
	    else
	    {
			var->d.oldDirX = var->d.dirX;
			var->d.dirX = var->d.dirX * cos(var->d.rotate) - var->d.dirY * sin(var->d.rotate);
			var->d.dirY = var->d.oldDirX * sin(var->d.rotate) + var->d.dirY * cos(var->d.rotate);
			var->d.oldPlaneX = var->d.planeX;
			var->d.planeX = var->d.planeX * cos(var->d.rotate) - var->d.planeY * sin(var->d.rotate);
			var->d.planeY = var->d.oldPlaneX * sin(var->d.rotate) + var->d.planeY * cos(var->d.rotate);
	    }
	}
	   var->d.oldDirX = x;
    return (0);
}
