/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:06:44 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/17 13:23:12 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_width_wall(t_var *var)
{
	if (var->d.side == 0 || var->d.side == 1)
		var->d.perpWallDist = ((double)var->d.mapX - var->d.posX +\
									(1 - var->d.stepX) / 2) / var->d.raydirX;
	else
		var->d.perpWallDist = ((double)var->d.mapY - var->d.posY +\
	 								(1 - var->d.stepY) / 2) / var->d.raydirY;
	if (var->d.perpWallDist == -0.0)
		var->d.perpWallDist = 0.5;
	var->d.lineHeight = (int)(WIN_X / var->d.perpWallDist);
	var->d.drawStart = -var->d.lineHeight / 2 + WIN_X / 2;
	if (var->d.drawStart < 0)
		var->d.drawStart = 0;
	var->d.drawEnd = var->d.lineHeight / 2 + WIN_X / 2;
	if (var->d.drawEnd >= WIN_X)
		var->d.drawEnd = WIN_X - 1;
}

void	ft_lancer_de_rayon(t_var *var)
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
		if ((var->d.mapX < var->parsing.max.x && var->d.mapX > 0) && (var->d.mapY < var->parsing.max.y && var->d.mapY > 0))
		{
			if (var->parsing.tab[var->d.mapX][var->d.mapY] > 0 && var->parsing.tab[var->d.mapX][var->d.mapY] != 9) // le rayon a trouvé une mur
				var->d.hit = 1;
			if (var->parsing.tab[var->d.mapX][var->d.mapY] == 2 && var->d.del == 1)
				var->parsing.tab[var->d.mapX][var->d.mapY] = 0;
		}
		else
		 	var->d.hit = 1;
	}
}

void	ft_condtion_ray(t_var *var)
{
	if (var->d.raydirX < 0)
	{
		var->d.stepX = -1;
		var->d.sideDistX = (var->d.posX - (double)var->d.mapX) * \
			var->d.deltaDistX;
	}
	else
	{
		var->d.stepX = 1;
		var->d.sideDistX = ((double)var->d.mapX + 1.0 - var->d.posX) * \
			var->d.deltaDistX;
	}
	if (var->d.raydirY < 0)
	{
		var->d.stepY = -1;
		var->d.sideDistY = (var->d.posY - var->d.mapY) * var->d.deltaDistY;
	}
	else
	{
		var->d.stepY = 1;
		var->d.sideDistY = (var->d.mapY + 1.0 - var->d.posY) * \
			var->d.deltaDistY;
	}
}

void	ft_init_raycasting(t_var *var, int x)
{
	var->d.cameraX = (2 * x / (double)WIN_X) - 1;
	var->d.raydirX = var->d.dirX + var->d.planeX * var->d.cameraX;
	var->d.raydirY = var->d.dirY + var->d.planeY * var->d.cameraX;
	var->d.mapX = (int)var->d.posX;
	var->d.mapY = (int)var->d.posY;
	var->d.deltaDistX = fabs(1 / var->d.raydirX);
	var->d.deltaDistY = fabs(1 / var->d.raydirY);
	var->d.hit = 0;
	ft_condtion_ray(var);
}

void	ft_raycasting(t_var *var)
{
	int x;
	int y;

	x = -1;
	y = 0;
	while (++x < WIN_X)
	{
		ft_init_raycasting(var, x);
		ft_lancer_de_rayon(var);
		ft_width_wall(var);
		mur(var, x, y);
		ciel(var, x, y);
		sol(var, x, y);
	}
	ft_put_map(var);
	ft_aff_obj(var);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->mlx.img, 0, 0);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->d.pistol, 350, 680);
	ft_menu(var);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->d.menu, 565, 710);
	// mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->d.start_menu, 0, 0);
	fps_counter(var);
}
