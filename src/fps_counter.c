/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/14 06:00:59 by vguerand         ###   ########.fr       */
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
	if (var->d.frametime < 0)
		fps_counter(var);
	tmp = ft_itoa((int)var->d.frametime);
	mlx_string_put(var->d.init, var->d.win, WIN_X / 100, WIN_Y / 100, \
		0xFF0000, "FPS:");
	mlx_string_put(var->d.init, var->d.win, WIN_X / 100 + 40, \
		WIN_Y / 100, 0xFF0000, tmp);
	free(tmp);
	var->d.movespeed = var->d.frametime * var->d.speed;
	var->d.rotate = var->d.frametime * 0.003;
}

# define PI 3.1415926535897932384626433832795028841971693993751058209749445923

static double		ft_deg_to_rad(int angle)
{
	return ((angle / PI) / 180);
}


t_coord				project_iso(t_var *var, t_coord pos, int denom)
{
	t_coord	v;
	double	al;
	double	beta;
	double	teta;
	int z = 1;



	pos.x *= denom;
	pos.y *= denom;
	al = ft_deg_to_rad(var->alpha);
	beta = ft_deg_to_rad(var->beta);
	teta = ft_deg_to_rad(var->teta);

	v.x = (pos.x) * cos(al) + (pos.y) * cos(beta) + z  * cos(teta);
	v.y = (pos.x) * sin(al) + (pos.y) * sin(beta) + z * sin(teta);
		// v.x = (p.x + l->x) + (p.z * 0.2 * l->z);
	if (denom != 1)
	{
		v.x += var->map.x;
		v.y += var->map.y;
	}
			// v.y = (p.y + l->y) + (p.z * 0.2 * l->z);
	return (v);
}

static void		mlx_put_pixel_image_square(t_var *var, t_coord pos, int color, int denom)
{
	int	x1;
	int	y1;
	t_coord project;

	x1 = pos.x;
	while (x1++ <= pos.x + denom)
	{
		y1 = pos.y;
		while (y1++ <= pos.y + denom)
		{
			project.x = y1;
			project.y = x1;
			// project = project_iso(var, project, 1);
			mlx_pixel_put_to_image(var->d, project.x, project.y, color);
		}
	}
}



void	ft_put_map(t_var *var)
{
	t_coord it;
	int denom;

	if (var->parsing.max.y > var->parsing.max.x)
		denom = var->parsing.max.y / 3;
	else
		denom = var->parsing.max.x / 3;
	it.y = 0;
	// denom *= 4; //pour zoomer
	while (it.y < var->parsing.max.y)
	{
		it.x = 0;
		while (it.x < var->parsing.max.x)
		{
			if (var->parsing.tab[it.y][it.x] == 9)
				mlx_put_pixel_image_square(var, project_iso(var, it, denom), 0x0000FF, denom);
			if (var->parsing.tab[it.y][it.x] > 0 && var->parsing.tab[it.y][it.x] != 9)
				mlx_put_pixel_image_square(var, project_iso(var, it, denom), 0x000000, denom);
			// if (var->parsing.tab[it.y][it.x] == 0)
				// mlx_put_pixel_image_square(var, project_iso(var, it, denom), 0x9E9E9E, denom);
			if (((int)var->d.posX == it.y && (int)var->d.posY == it.x))
				mlx_put_pixel_image_square(var, project_iso(var, it, denom), 0xFF0000, denom);
			if ((((int)(var->d.raydirX * 2) + (int)var->d.posX)) == it.y && ((int)(var->d.raydirY * 2) + (int)var->d.posY) == it.x)
				mlx_put_pixel_image_square(var, project_iso(var, it, denom), 0x00FF0f, denom);
			it.x++;
		}
		it.y++;
	}
}
