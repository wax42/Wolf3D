/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/05 17:42:14 by wsabates         ###   ########.fr       */
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


static void		mlx_put_pixel_image_square(t_var *var, int x, int y, int color, int denom)
{
	int	i;
	int	j;

	i = 0;
	while (i++ <= denom)
	{
		j = 0;
		while (j++ <= denom)
			mlx_pixel_put_to_image(var->d, x + i, y + j, color);
	}
}

void	ft_put_map(t_var *var)
{
	int i;
	int j;
	int denom;

	if (var->parsing.max.y > var->parsing.max.x)
		denom = var->parsing.max.y / 4;
	else
		denom = var->parsing.max.x / 4;
	i = 0;
	while (i < var->parsing.max.y)
	{
		j = 0;
		while (j < var->parsing.max.x)
		{
			if (var->parsing.tab[j][i] > 0)
				mlx_put_pixel_image_square(var, i * denom, j * denom, 0x000000, denom);
			else
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
