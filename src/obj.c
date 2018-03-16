/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:21:08 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/16 15:44:41 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void 	ft_init_obj(t_var *var, int x, int y)
{
	double invDet;

	double spriteX;
	double spriteY;

	var->o.coord.x = x;
	var->o.coord.y = y;
	spriteX = (double)(x) + 0.4 - var->d.posX; // calcul de la longeur du rayon seulement quqnd on touche l obj
	spriteY = (double)(y) + 0.4 - var->d.posY; // calcul de la longeur du rayon seulement quqnd on touche l obj
	invDet = 1.0 / (var->d.planeX * var->d.dirY - var->d.dirX * var->d.planeY); // requis pour une bonne multiplication de la matrice
	var->o.transformX = invDet * (var->d.dirY * spriteX - var->d.dirX * spriteY);
	var->o.transformY = invDet * (-var->d.planeY * spriteX + var->d.planeX * spriteY); // c'est en fait la profondeur à l'intérieur de l'écran, que Z est en 3D
	var->o.spriteScreenX = (int)((WIN_Y / 2) * (1 + var->o.transformX / var->o.transformY));
	var->s.vMoveScreen = (int)(vMove / var->o.transformY);
	var->o.spriteHeight = abs((int)(WIN_X / var->o.transformY)) / vDiv; ///bellec au Y
	printf("transforlmY%fvar->o.spriteHeight%f\n", var->o.transformY, var->o.spriteHeight);

	 // calculer le pixel le plus bas et le plus haut pour remplir la bande courante
	var->o.drawStartY = -var->o.spriteHeight / 2 + WIN_X / 2 + var->s.vMoveScreen;
	if (var->o.drawStartY < 0)
		var->o.drawStartY = 0;
	var->o.drawEndY = var->o.spriteHeight / 2 + WIN_X / 2 + var->s.vMoveScreen;
	if (var->o.drawEndY >= WIN_X)
		var->o.drawEndY = WIN_X - 1;

      // calcule la largeur de l'image-objet
	var->o.spriteWidth = abs((int)(WIN_X / var->o.transformY)) / uDiv; ///bellec au Y
	var->o.drawStartX = -var->o.spriteWidth / 2 + var->o.spriteScreenX;
	if (var->o.drawStartX < 0)
		var->o.drawStartX = 0;
	var->o.drawEndX = var->o.spriteWidth / 2 + var->o.spriteScreenX;
	if (var->o.drawEndX >= WIN_X)
		var->o.drawEndX = WIN_X - 1;
	var->o.bol = 1;
}

int	ft_lancer_d_obj(t_var *var)
{
	while (var->d.hit == 0)
	{
		if (var->d.sideDistX < var->d.sideDistY)
		{
			var->d.sideDistX += var->d.deltaDistX;
			var->d.mapX += var->d.stepX; // pour faire avancer la position du rayon sur la map
		}
		else
		{
			var->d.sideDistY += var->d.deltaDistY;
			var->d.mapY += var->d.stepY;
		}
		if (var->d.mapX < 24 && var->d.mapX >= 0 && var->d.mapY < 24 && var->d.mapY >= 0)
		{
			if (var->d.mapX == var->o.coord.x && var->d.mapY == var->o.coord.y) // le rayon a trouvé un obj
				return (1);
			else if (var->parsing.tab[var->d.mapX][var->d.mapY] > 0 && var->parsing.tab[var->d.mapX][var->d.mapY] != 9) // le rayon a trouvé une mur
				return (0);
		}
	}
	return (0);
}

int 	obj_check(t_var *var, int x)
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
	return (ft_lancer_d_obj(var));
}

void 	objet(t_var *var, int x, int y)
{
	int texture_x;
	int texture_y;
	int d;
	int color_g;
	int color_b;
	int color_r;
	int i;

	ft_init_obj(var, x, y);

      // boucle sur toutes les bandes verticales de l'image-objet à l'écran
	x = var->o.drawStartX;
	while (x++ < var->o.drawEndX)
	{
		texture_x = (int)(256 * (x - (-var->o.spriteWidth / 2 + var->o.spriteScreenX)) * var->t.w_texture_obj / var->o.spriteWidth) / 256;
		y = var->o.drawStartY;
		if (obj_check(var, x))
		{

			if(var->o.transformY > 0 && x > 0 && x < WIN_X && var->o.transformY < var->parsing.tab[var->d.mapX][var->d.mapY])
			{
			while (++y < var->o.drawEndY)// pour chaque pixel de la bande courante
			{
				d = ((y - var->s.vMoveScreen) * 256 - WIN_Y * 128 + var->o.spriteHeight * 128);
				texture_y = ((d * var->t.h_texture_obj) / var->o.spriteHeight) / 256;
				if (texture_y > 0)
				{
					i = (texture_y * var->t.w_texture_obj + texture_x) * 4;
					color_r = var->t.texture_obj[i + 2];
					color_g = var->t.texture_obj[i + 1];
					color_b = var->t.texture_obj[i];
					i = (y * WIN_X + x) * 4;
					if (i > 0 && i < (WIN_X * WIN_X * 4) && (color_r != 152 && color_g != 0 && color_b != 136))
						mlx_pixel_put_to_image(var->mlx, x, y, rgb_to_hexa(color_r, color_g, color_b));
					}
				}

			}
		}
	}
}
