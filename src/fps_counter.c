/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/01 02:43:40 by vguerand         ###   ########.fr       */
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


static void		mlx_put_pixel_image_square(t_var *var, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i++ <= 5)
	{
		j = 0;
		while (j++ <= 5)
			mlx_pixel_put_to_image(var->d, x + i, y + j, color);
	}
}

void	ft_put_map(t_var *var)
{
	int i;
	int j;

	i = 0;
	while (i < var->parsing.max.y)
	{
		j = 0;
		while (j < var->parsing.max.x)
		{
			if (var->parsing.tab[j][i] == 1)
				mlx_put_pixel_image_square(var, i * 5, j * 5, 0x0000FF);
			else
				mlx_put_pixel_image_square(var, i * 5, j * 5, 0xFFFFFF);
			if (((int)var->d.posX == j && (int)var->d.posY == i))
				mlx_put_pixel_image_square(var, i * 5, j * 5, 0xf4429e);
			j++;
		}
		i++;
	}
}
