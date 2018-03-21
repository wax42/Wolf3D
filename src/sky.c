/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:23 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/19 13:43:06 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	calculate_sky(t_var *var)
{
	var->f.weight = (var->r.currentdist - var->f.distplayer) / \
									(var->r.distwall - var->f.distplayer);
	var->f.current_floor_sky_x = var->f.weight * var->f.floor_sky_wallx +\
										(1.0 - var->f.weight) * var->r.posx;
	var->f.current_floor_sky_y = var->f.weight * var->f.floor_sky_wally + \
										(1.0 - var->f.weight) * var->r.posy;
	var->f.floor_sky_tex_x = (int)(var->f.current_floor_sky_x * \
										var->t.w_tex_sky) % var->t.w_tex_sky;
	var->f.floor_sky_tex_y = (int)(var->f.current_floor_sky_y * \
										var->t.h_tex_sky) % var->t.h_tex_sky;
}

void	sky_find_side(t_var *var)
{
	if ((var->r.side == 0 || var->r.side == 1) && var->r.raydirx > 0)
	{
		var->f.floor_sky_wallx = var->r.mapx;
		var->f.floor_sky_wally = var->r.mapy + var->r.wallx;
	}
	else if ((var->r.side == 0 || var->r.side == 1) && var->r.raydirx < 0)
	{
		var->f.floor_sky_wallx = var->r.mapx + 1.0;
		var->f.floor_sky_wally = var->r.mapy + var->r.wallx;
	}
	else if ((var->r.side == 2 || var->r.side == 3) && var->r.raydiry > 0)
	{
		var->f.floor_sky_wallx = var->r.mapx + var->r.wallx;
		var->f.floor_sky_wally = var->r.mapy;
	}
	else
	{
		var->f.floor_sky_wallx = var->r.mapx + var->r.wallx;
		var->f.floor_sky_wally = var->r.mapy + 1.0;
	}
	var->r.distwall = var->r.perpwalldist;
	var->f.distplayer = 0.0;
	if (var->r.drawend < 0)
		var->r.drawend = WIN_X;
}

void	sky(t_var *var, int x, int y)
{
	int i;
	int color_g;
	int color_b;
	int color_r;

	sky_find_side(var);
	y = var->r.drawend - 1;
	while (y++ < WIN_X)
	{
		var->r.currentdist = WIN_X / (2.0 * y - WIN_X);
		calculate_sky(var);
		i = (var->t.w_tex_sky * var->f.floor_sky_tex_y + \
													var->f.floor_sky_tex_x) * 4;
		color_r = var->t.tex_sky[i + 2];
		color_g = var->t.tex_sky[i + 1];
		color_b = var->t.tex_sky[i];
		mlx_pixel_put_to_image(var->mlx, x, WIN_Y - y, \
										rgb_to_hexa(color_r, color_g, color_b));
	}
}
