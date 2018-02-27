/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:06:44 by wsabates          #+#    #+#             */
/*   Updated: 2018/02/27 15:45:08 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"


// #define mapWidth 24
// #define mapHeight 24
//
// int var->tab[mapWidth][mapHeight]=
// {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };
//


void ft_fonc(t_var *var)
{
	int x;
	int y;

	x = -1;
	y = 0;
	while(++x < WIN_X)
	{
		var->d.cameraX = (2 * x / (double)WIN_X) - 1; //position en x de notre champ de vison
		// var->d.raydirX = var->d.posX;
		// var->d.raydirY = var->d.posY;
		var->d.raydirX = var->d.dirX + var->d.planeX * var->d.cameraX; // dirsction en x de rayon raycaster
		var->d.raydirY = var->d.dirY + var->d.planeY * var->d.cameraX; // dirsction en y de rayon raycaster
		var->d.mapX = (int)var->d.posX; // notre position en int sur le tableau
		var->d.mapY = (int)var->d.posY;
		var->d.deltaDistX = fabs(1 / var->d.raydirX); // la distance que le rayon doit parcourir en x dans chaque carre de du tableau
		var->d.deltaDistY = fabs(1 / var->d.raydirY);
		var->d.hit = 0; // si il y a un mur ou non
		if (var->d.raydirX < 0)
		{
			var->d.stepX = -1;
			var->d.sideDistX = (var->d.posX - var->d.mapX) * var->d.deltaDistX;
		}
		else
		{
			var->d.stepX = 1;
			var->d.sideDistX = (var->d.mapX + 1.0 - var->d.posX) * var->d.deltaDistX;// longueur coter droit des murs pour un bon raccordement sans troue
		}
		if (var->d.raydirY < 0)
		{
			var->d.stepY = -1;
			var->d.sideDistY = (var->d.posY - var->d.mapY) * var->d.deltaDistY;
		}
		else
		{
			var->d.stepY = 1;
			var->d.sideDistY = (var->d.mapY + 1.0 - var->d.posY) * var->d.deltaDistY;// longueur en  des murs pour un bon raccordement sans troue
		}
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
			if (var->tab[var->d.mapX][var->d.mapY] > 0) // le rayon a trouvé une mur
				var->d.hit = 1;
		}
		if (var->d.side == 0 || var->d.side == 1)
			var->d.perpWallDist = (var->d.mapX - var->d.posX + (1 - var->d.stepX) / 2) / var->d.raydirX; // calcul de la longeur du rayon seulement quqnd on touche le mur
		else
			var->d.perpWallDist = (var->d.mapY - var->d. posY + (1 - var->d.stepY) / 2) / var->d.raydirY;
		var->d.lineHeight = (int)(WIN_X / var->d.perpWallDist);
		var->d.drawStart = -var->d.lineHeight / 2 + WIN_X / 2;
		if (var->d.drawStart < 0)
			var->d.drawStart = 0;
		var->d.drawEnd = var->d.lineHeight / 2 + WIN_X / 2;
		if (var->d.drawEnd >= WIN_X)
			var->d.drawEnd = WIN_X - 1;
		sol(var, x, y);
		ciel(var, x ,y);
		mur(var, x, y);
	}
	mlx_put_image_to_window(var->d.mlx, var->d.win, var->d.img, 0, 0);
//fps_counter(var);
}
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
	if (keycode ==0)
	{
		var->d.raydirY +=1;
	}
	 ft_fonc(var);
	// mlx_destroy_image(var->d.mlx, var->d.img);
	// var->d.img = mlx_new_image(var->d.mlx, WIN_X, WIN_Y);
	// var->d.map = mlx_get_data_addr(var->d.img, &var->d.bpp, \
	// 	&var->d.size_line, &var->d.endian);
	printf("keycode = %d\n", keycode);
	return (0);
}

int main(int argc, char **av)
{
	t_var var;

	ft_putstr("oui");
	ft_putstr("oui");
	if (argc == 2)
		var.tab = parsing(av[1]);
	var.d.mlx = mlx_init();
	ft_init_struct(&var);
	var.d.win = mlx_new_window(var.d.mlx, WIN_X, WIN_Y, "dd");
	var.d.img = mlx_new_image(var.d.mlx, WIN_X, WIN_Y);
	var.d.map = mlx_get_data_addr(var.d.img, &var.d.bpp, \
		&var.d.size_line, &var.d.endian);
	//var.d.win = mlx_new_window(var.d.mlx, WIN_X, WIN_Y, "dd");
	ft_fonc(&var);
	mlx_hook(var.d.win, 2, (1L << 0), my_key_funct, &var);
	//mlx_loop_hook(var.d.init, (int(*)())ft_fonc, &var);
	mlx_loop(var.d.mlx);
}
