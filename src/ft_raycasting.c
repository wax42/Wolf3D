/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:06:44 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/01 02:20:37 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_width_wall(t_var *var)
{
	if (var->d.side == 0 || var->d.side == 1)
		var->d.perpWallDist = (var->d.mapX - var->d.posX + 0.1 +\
									(1 - var->d.stepX) / 2) / var->d.raydirX; // calcul de la longeur du rayon seulement quqnd on touche le mur
	else
		var->d.perpWallDist = (var->d.mapY - var->d.posY + 0.1 +\
									(1 - var->d.stepY) / 2) / var->d.raydirY;
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
			var->d.mapX += var->d.stepX; // pour faire avancer la position du rayon sur la map
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
		if (var->d.mapX < 24.0 && var->d.mapX >= 0.0 && var->d.mapY < 24.0 && var->d.mapY >= 0.0)
		{
			if (var->tab[var->d.mapX][var->d.mapY] > 0) // le rayon a trouvé une mur
			{
				var->d.hit = 1;
			}
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
		var->d.sideDistX = (var->d.posX - (double)var->d.mapX) * var->d.deltaDistX;
	}
	else
	{
		var->d.stepX = 1;
		var->d.sideDistX = ((double)var->d.mapX + 1.0 - var->d.posX) * \
															var->d.deltaDistX;// longueur coter droit des murs pour un bon raccordement sans troue
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
															var->d.deltaDistY;// longueur en  des murs pour un bon raccordement sans troue
	}
}

void	ft_init_raycasting(t_var *var, int x)
{
	var->d.cameraX = (2 * x / (double)WIN_X) - 1; //position en x de notre champ de vison
	var->d.raydirX = var->d.dirX + var->d.planeX * var->d.cameraX; // dirsction en x de rayon raycaster
	var->d.raydirY = var->d.dirY + var->d.planeY * var->d.cameraX; // dirsction en y de rayon raycaster
	var->d.mapX = (int)var->d.posX; // notre position en int sur le tableau
	var->d.mapY = (int)var->d.posY;
	var->d.deltaDistX = fabs(1 / var->d.raydirX); // la distance que le rayon doit parcourir en x dans chaque carre de du tableau
	var->d.deltaDistY = fabs(1 / var->d.raydirY);
	var->d.hit = 0; // si il y a un mur ou non
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
		sol(var, x, y);
		ciel(var, x, y);
		mur(var, x, y);
	}
	ft_put_map(var);
	mlx_put_image_to_window(var->d.mlx, var->d.win, var->d.img, 0, 0);
}
