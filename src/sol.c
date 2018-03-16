/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:11 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/15 22:53:45 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	sol(t_var *var, int x, int y)
{
	int i;
	int color_g;
	int color_b;
	int color_r;

	if ((var->d.side == 0 || var->d.side == 1) && var->d.raydirX > 0)
	{
		var->d.floorXwall = var->d.mapX;
		var->d.floorYwall = var->d.mapY + var->d.wallX;
	}
	else if ((var->d.side == 0 || var->d.side == 1) && var->d.raydirX < 0)
	{
		var->d.floorXwall = var->d.mapX + 1.0;
		var->d.floorYwall = var->d.mapY + var->d.wallX;
	}
	else if ((var->d.side == 2 || var->d.side == 3) && var->d.raydirY > 0)
	{
		var->d.floorXwall = var->d.mapX + var->d.wallX;
		var->d.floorYwall = var->d.mapY;
	}
	else
	{
		var->d.floorXwall = var->d.mapX + var->d.wallX;
		var->d.floorYwall = var->d.mapY + 1.0;
	}
	var->d.distWall = var->d.perpWallDist;
	var->d.distPlayer = 0.0;
	if (var->d.drawEnd < 0)
		var->d.drawEnd = WIN_X;
	y = var->d.drawEnd - 1;
	while (y++ < WIN_X)
	{
		var->d.currentDist = WIN_X / (2.0 * y - WIN_X);
		var->d.weight = (var->d.currentDist - var->d.distPlayer) / (var->d.distWall - var->d.distPlayer);
		var->d.currentFloorX = var->d.weight * var->d.floorXwall + (1.0 - var->d.weight) * var->d.posX;
		var->d.currentFloorY = var->d.weight * var->d.floorYwall + (1.0 - var->d.weight) * var->d.posY ;
		var->d.floorTexX = (int)(var->d.currentFloorX * var->t.w_texture_floor) % var->t.w_texture_floor;
		var->d.floorTexY = (int)(var->d.currentFloorY * var->t.h_texture_floor) % var->t.h_texture_floor;
		i = (var->t.w_texture_floor * var->d.floorTexY + var->d.floorTexX) * 4;
		color_r = var->t.texture_floor[i + 2];
		color_g = var->t.texture_floor[i + 1];
		color_b = var->t.texture_floor[i];
		mlx_pixel_put_to_image(var->mlx, x, y, rgb_to_hexa(color_r, color_g, color_b));
	}
}
