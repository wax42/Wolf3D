/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mur.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:04 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/15 22:53:54 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		rgb_to_hexa(int r, int g, int b)
{
	return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
}


void ft_texture_orientation(t_var *var)
{
	if (var->d.side == 0)
	{
		var->t.texture = var->t.tex_mur_nord;
		var->t.w_texture = var->t.w_tex_mur_nord;
		var->t.h_texture = var->t.h_tex_mur_nord;
	}
	else if (var->d.side == 1)
	{
		var->t.texture = var->t.tex_mur_sud;
		var->t.w_texture = var->t.w_tex_mur_sud;
		var->t.h_texture = var->t.h_tex_mur_sud;
	}
	else if (var->d.side == 2)
	{
		var->t.texture = var->t.tex_mur_west;
		var->t.w_texture = var->t.w_tex_mur_west;
		var->t.h_texture = var->t.h_tex_mur_west;
	}
	else
	{
		var->t.texture = var->t.tex_mur_est;
		var->t.w_texture = var->t.w_tex_mur_est;
		var->t.h_texture = var->t.h_tex_mur_est;
	}
}


void ft_value_wall(t_var *var)
{
	ft_texture_orientation(var);
	if (var->d.side == 0 || var->d.side == 1)
		var->d.wallX = var->d.posY + var->d.perpWallDist * var->d.raydirY;//La valeur wallX représente la valeur exacte à laquelle le mur a été touché
	else
		var->d.wallX = var->d.posX + var->d.perpWallDist * var->d.raydirX;
	var->d.wallX -= floor(var->d.wallX);
	var->t.texture_x = (int)(var->d.wallX * (double)var->t.w_texture);
	if (var->d.side == 0 && var->d.raydirX > 0)
		var->t.texture_x -= var->t.w_texture - 1;
	if (var->d.side == 1 && var->d.raydirY < 0)
		var->t.texture_x -= var->t.w_texture - 1;
}

void	mur(t_var *var, int x, int y)
{
	int texture_y;
	int d;
	int color_g;
	int color_b;
	int color_r;
	int i;

	ft_value_wall(var);
	y = var->d.drawStart - 1;
	while (++y < var->d.drawEnd)
	{
		d = y * 256 - WIN_X * 128 + (var->d.lineHeight) * 128;
		texture_y = (d *  var->t.h_texture) / (var->d.lineHeight) / 256;
		if (texture_y >= 0)
		{
			i = (texture_y * var->t.w_texture + var->t.texture_x) * 4;
			color_r = var->t.texture[i + 2];
			color_g = var->t.texture[i + 1];
			color_b = var->t.texture[i];
			i = (y * WIN_X + x) * 4;
			if (i > 0 && i < (WIN_X * WIN_X * 4))
				mlx_pixel_put_to_image(var->mlx, x, y, rgb_to_hexa(color_r, color_g, color_b));
		}
	}
}
