/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:51:05 by wsabates          #+#    #+#             */
/*   Updated: 2018/02/27 02:27:48 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

#define mapWidth 24
#define mapHeight 24


// int var->tab[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

int my_key_funct(int keycode, t_var *var)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
	{
		printf("posX = %f\n", var->d.posX);
		printf("posY = %f\n", var->d.posY);
		if(var->tab[(int)(var->d.posX + var->d.dirX * var->d.movespeed)] [(int)(var->d.posY)] == 0)
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
	  var->d.dirX = var->d.dirX * cos(-var->d.rotspeed) - var->d.dirY * sin(-var->d.rotspeed);
	  var->d.dirY = var->d.oldDirX * sin(-var->d.rotspeed) + var->d.dirY * cos(-var->d.rotspeed);
	  var->d.oldPlaneX = var->d.planeX;
	  var->d.planeX = var->d.planeX * cos(-var->d.rotspeed) - var->d.planeY * sin(-var->d.rotspeed);
	  var->d.planeY = var->d.oldPlaneX * sin(-var->d.rotspeed) + var->d.planeY * cos(-var->d.rotspeed);
	}
	if (keycode == 123)
	{
		var->d.oldDirX = var->d.dirX;
      var->d.dirX = var->d.dirX * cos(var->d.rotspeed) - var->d.dirY * sin(var->d.rotspeed);
      var->d.dirY = var->d.oldDirX * sin(var->d.rotspeed) + var->d.dirY * cos(var->d.rotspeed);
      var->d.oldPlaneX = var->d.planeX;
      var->d.planeX = var->d.planeX * cos(var->d.rotspeed) - var->d.planeY * sin(var->d.rotspeed);
      var->d.planeY = var->d.oldPlaneX * sin(var->d.rotspeed) + var->d.planeY * cos(var->d.rotspeed);
	}
	// mlx_destroy_image(var->d.mlx, var->d.img);
	// var->d.img = mlx_new_image(var->d.mlx, WIN_X, WIN_Y);
	// var->d.map = mlx_get_data_addr(var->d.img, &var->d.bpp, \
	// 	&var->d.size_line, &var->d.endian);
	//printf("keycode = %d\n", keycode);
	return (0);
}

void	raycaster_fih(t_var *var)
{
	if (var->d.side == 0 || var->d.side == 1)
		var->d.perpWallDist = (var->d.mapX - var->d.raydirX + (1 - var->d.stepX) \
		/ 2) / var->d.raydirX;
	else
		var->d.perpWallDist = (var->d.mapY - var->d.raydirY + (1 - var->d.stepY) \
		/ 2) / var->d.raydirY;
	var->d.lineHeight = (int)(WIN_Y / var->d.perpWallDist);
	var->d.drawStart = (-var->d.lineHeight / 2) + (WIN_Y / 2);
	if (var->d.drawStart < 0)
		var->d.drawStart = 0;
	var->d.drawEnd = (var->d.lineHeight / 2) + (WIN_Y / 2);
	if (var->d.drawEnd >= WIN_Y)
		var->d.drawEnd = WIN_Y - 1;
}

void	raycaster_fh(t_var *var)
{
	while (var->d.hit == 0)
	{
		if (var->d.sideDistX < var->d.sideDistY)
		{
			var->d.sideDistX += var->d.deltaDistX;
			var->d.mapX += var->d.stepX;
			if (var->d.stepX == -1)
				var->d.side = 0;
			if (var->d.stepX == 1)
				var->d.side = 1;
		}

		else
		{
			var->d.sideDistY += var->d.deltaDistY;
			var->d.mapY += var->d.stepY;
			if (var->d.stepY == -1)
				var->d.side = 2;
			if (var->d.stepY == 1)
				var->d.side = 3;
		}
		if (var->tab[var->d.mapX][var->d.mapY] > 0)
			var->d.hit = 1;
	}
}

void	raycaster_td(t_var *var)
{
	if (var->d.raydirX < 0)
	{
		var->d.stepX = -1;
		var->d.sideDistX = (var->d.raydirX - var->d.mapX) * var->d.deltaDistX;
	}
	else
	{
		var->d.stepX = 1;
		var->d.sideDistX = (var->d.mapX + 1.0 - var->d.raydirX) * var->d.deltaDistX;
	}
	if (var->d.raydirY < 0)
	{
		var->d.stepY = -1;
		var->d.sideDistY = (var->d.raydirY - var->d.mapY) * var->d.deltaDistY;
	}
	else
	{
		var->d.stepY = 1;
		var->d.sideDistY = (var->d.mapY + 1.0 - var->d.raydirY) * var->d.deltaDistY;
	}
}

void	raycaster_sd(t_var *var, int x)
{
	var->d.cameraX = 2 * x / (double)WIN_X - 1;
	var->d.raydirX = var->d.posX;
	var->d.raydirY = var->d.posY;
	var->d.raydirX = var->d.dirX + var->d.planeX * var->d.cameraX;
	var->d.raydirY = var->d.dirY + var->d.planeY * var->d.cameraX;
	var->d.mapX = (int)var->d.raydirX;
	var->d.mapY = (int)var->d.raydirY;
	var->d.deltaDistX = sqrt(1 + (var->d.raydirY * var->d.raydirY) / \
	(var->d.raydirX * var->d.raydirX));
	var->d.deltaDistY = sqrt(1 + (var->d.raydirX * var->d.raydirX) / \
	(var->d.raydirY * var->d.raydirY));
	var->d.hit = 0;
}

void	raycaster(t_var *var)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (++x < WIN_X)
	{
		raycaster_sd(var, x);
		raycaster_td(var);
		raycaster_fh(var);
		raycaster_fih(var);
		mur(var, x, y);
		sol(var, x, y);
		ciel(var, x, y);
	}
	mlx_put_image_to_window(var->d.mlx, var->d.win, var->d.img, 0, 0);
	//fps_counter(a);
}
