/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 02:37:27 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 13:44:22 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

#define PISTOLX 360
#define PISTOLY 680

void	mlx_put_image_to_image(t_var *var)
{
	int y;
	int x;
	int i;
	int color;

	x = 0;
	while (x++ < var->t.w_pistol - 10)
	{
		y = 0;
		while (++y < var->t.h_pistol)
		{
			i = (y * var->t.w_pistol + x) * 4;
			color = rgb_to_hexa(var->t.t_pistol[i + 2], var->t.t_pistol[i + 1],\
															var->t.t_pistol[i]);
			if (color != 9961608)
				mlx_pixel_put_to_image(var->mlx, x + PISTOLX, y + PISTOLY, \
																		color);
		}
	}
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
		sky(var, x, y);
		ft_floor(var, x, y);
	}
	ft_put_map(var);
	ft_aff_obj(var);
	ft_menu(var);
	mlx_put_image_to_image(var);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->mlx.img, 0, 0);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->r.menu, 577, 735);
	ft_fps_counter(var);
}
