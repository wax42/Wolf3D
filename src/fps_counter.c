/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/16 17:50:22 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	fps_counter(t_var *var)
{
	struct timeval	tp;
	char			*tmp;

	var->d.oldtime = var->d.time;
	gettimeofday(&tp, NULL);
	var->d.time = tp.tv_usec;
	var->d.frametime = round((var->d.time - var->d.oldtime) / 1000);
	// if (var->d.frametime < 0)
		// fps_counter(var);
	tmp = ft_itoa((int)var->d.frametime);
	// mlx_string_put(var->d.mlx, var->d.img, WIN_X / 100, WIN_Y / 100,
		// 0xFF0000, "FPS:");
	// mlx_string_put(var->d.mlx, var->d.img, WIN_X / 100 + 40,
		// WIN_Y / 100, 0xFF0000, tmp);
	printf("FPS:%s\n", tmp);
	free(tmp);
	// var->d.movespeed = var->d.frametime * var->d.speed;
	// var->d.rotate = var->d.frametime * 0.003;
}

// mlx_look_key //mlx_loop_hook(a->mlx.mlx, (int(*)())raycaster, var); pour mettre le fps

# define PI 3.1415926535897932384626433832795028841971693993751058209749445923

static double		ft_deg_to_rad(int angle)
{
	return ((angle / PI) / 180);
}


t_coord				project_iso(t_var *var, t_coord pos, int denom, int z)
{
	t_coord	v;
	double	al;
	double	beta;
	double	teta;


	pos.x *= denom;
	pos.y *= denom;

	al = ft_deg_to_rad(var->alpha);
	beta = ft_deg_to_rad(var->beta);
	teta = ft_deg_to_rad(var->teta);

	v.x = (pos.x) * cos(al) + (pos.y) * cos(beta + 2.0944) + z  * cos(teta + 2.0944);
	v.y = (pos.x) * sin(-al) + (pos.y) * sin(beta + 2.0944) + z * sin(teta + 2.0944);
		// v.x = (p.x + l->x) + (p.z * 0.2 * l->z);
	v.x += var->map.x;
	v.y += var->map.y;
	return (v);
}

// static void		mlx_put_pixel_image_square(t_var *var, t_coord pos, int color, int denom)
// {
// 	// int	x1;
// 	// int	y1;
// 	// t_coord project;
// 	denom = 1;
// 	mlx_pixel_put_to_image(var->mlx, pos.x, pos.y, color);
//
// 	// x1 = pos.x;
// 	// while (x1++ <= pos.x + denom)
// 	// {
// 	// 	y1 = pos.y;
// 	// 	while (y1++ <= pos.y + denom)
// 	// 	{
// 	// 		project.x = y1;
// 	// 		project.y = x1;
// 	// 		// project = project_iso(var, project, denom, 0);
// 	// 		mlx_pixel_put_to_image(var->mlx, project.x, project.y, color);
// 	// 	}
// 	}
// // }

static void		mlx_put_pixel_image_square(t_var *var, int x, int y, int color, int denom)
{
	int	i;
	int	j;

	i = 0;
	while (i++ <= denom)
	{
		j = 0;
		while (j++ <= denom)
			mlx_pixel_put_to_image(var->mlx, x + i, y + j, color);
	}
}

void	ft_put_map(t_var *var)
{
	int i;
	int j;
	int denom;

	if (var->parsing.max.y > var->parsing.max.x)
		denom = var->parsing.max.y / 3;
	else
		denom = var->parsing.max.x / 3;
	// denom *= 4;
	i = 0;
	while (i < var->parsing.max.y)
	{
		j = 0;
		while (j < var->parsing.max.x)
		{

			if (var->parsing.tab[j][i] == 9)
				mlx_put_pixel_image_square(var, i * denom, j * denom, 0x0000FF, denom);
			if (var->parsing.tab[j][i] > 0 && var->parsing.tab[j][i] != 9)
				mlx_put_pixel_image_square(var, i * denom, j * denom, 0x000000, denom);
			if (var->parsing.tab[j][i] == 0)
				mlx_put_pixel_image_square(var, i * denom, j * denom, 0x9E9E9E, denom);
			if (((int)var->d.posX == j && (int)var->d.posY == i))
				mlx_put_pixel_image_square(var, i * denom, j * denom, 0xFF0000, denom);
			if ((((int)(var->d.raydirX * 2) + (int)var->d.posX)) == j && ((int)(var->d.raydirY * 2) + (int)var->d.posY) == i)
				mlx_put_pixel_image_square(var, i * denom, j * denom, 0x00FF0f, denom);
			j++;
		}
		i++;

	}
}

// void	ft_put_map(t_var *var)
// {
// 	t_coord it;
// 	t_coord old[var->parsing.max.y][var->parsing.max.x];
//
// 	t_coord project;
// 	t_coord it2;
// 	int denom;
//
// 	if (var->parsing.max.y > var->parsing.max.x)
// 		denom = var->parsing.max.y / 3;
// 	else
// 		denom = var->parsing.max.x / 3;
// 	it.y = 0;
// 	denom *= 4; //pour zoomer
// 	while (it.y < var->parsing.max.y)
// 	{
// 		it.x = 0;
// 		while (it.x < var->parsing.max.x)
// 		{
// 			// var->map.z = 100;
// 			// var->parsing.map[it.y][it.x]
// 			project = project_iso(var, it, denom, var->parsing.tab[it.y][it.x] * 20);
// 			// old[it.y + var->parsing.max.y][it.x + var->parsing.max.x] = project_iso(var, it, denom, var->parsing.tab[it.y][it.x] * 20);
// 			if (it.x != 0)
// 			{
// 				it2 = old[it.y][it.x - 1];
// 				ft_ligne(var->mlx, project, it2, 0xFF00FF);
// 				// it2 = old[it.y][it.x + var->parsing.max.x - 1];
// 				// ft_ligne(var->mlx, project, it2, 0xFF00FF);
// 			}
// 			if (it.y != 0)
// 			{
// 				// it2 = old_y;
// 				it2 = old[it.y - 1][it.x];
// 				ft_ligne(var->mlx, project, it2, 0xFFFFF);
// 			}
// 			old[it.y][it.x] = project;
// 			// if (var->parsing.tab[it.y][it.x] == 9)
// 				// mlx_put_pixel_image_square(var, project_iso(var, it, denom, 1), 0x0000FF, denom);
// 			// if (var->parsing.tab[it.y][it.x] > 0 && var->parsing.tab[it.y][it.x] != 9)
// 				// mlx_put_pixel_image_square(var, project_iso(var, it, denom, 1), 0x000000, denom);
// 			// if (var->parsing.tab[it.y][it.x] == 0)
// 				// mlx_put_pixel_image_square(var, project_iso(var, it, denom), 0x9E9E9E, denom);
// 			// if (((int)var->d.posX == it.y && (int)var->d.posY == it.x))
// 			// 	mlx_put_pixel_image_square(var, project_iso(var, it, denom, 1), 0xFF0000, denom);
// 			// if ((((int)(var->d.raydirX * 2) + (int)var->d.posX)) == it.y && ((int)(var->d.raydirY * 2) + (int)var->d.posY) == it.x)
// 			// 	mlx_put_pixel_image_square(var, project_iso(var, it, denom, 1), 0x00FF0f, denom);
// 			it.x++;
// 		}
// 		it.y++;
// 	}
// }
