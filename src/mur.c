/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mur.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:04 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/18 03:59:09 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		rgb_to_hexa(int r, int g, int b)
{
	return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
}

void	ft_texture_orientation(t_var *var)
{
	if (var->r.side == 0)
	{
		var->t.texture = var->t.tex_mur_nord;
		var->t.w_texture = var->t.w_tex_mur_nord;
		var->t.h_texture = var->t.h_tex_mur_nord;
	}
	else if (var->r.side == 1)
	{
		var->t.texture = var->t.tex_mur_sud;
		var->t.w_texture = var->t.w_tex_mur_sud;
		var->t.h_texture = var->t.h_tex_mur_sud;
	}
	else if (var->r.side == 2)
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

void	ft_value_wall(t_var *var)
{
	ft_texture_orientation(var);
	if (var->r.side == 0 || var->r.side == 1)
		var->r.wallx = var->r.posy + var->r.perpwalldist * var->r.raydiry;
	else
		var->r.wallx = var->r.posx + var->r.perpwalldist * var->r.raydirx;
	var->r.wallx -= floor(var->r.wallx);
	var->t.texture_x = (int)(var->r.wallx * (double)var->t.w_texture);
	if (var->r.side == 0 && var->r.raydirx > 0)
		var->t.texture_x -= var->t.w_texture - 1;
	if (var->r.side == 1 && var->r.raydiry < 0)
		var->t.texture_x -= var->t.w_texture - 1;
}

void	mur(t_var *var, int x, int y)
{
	int d;
	int color_g;
	int color_b;
	int color_r;
	int i;

	ft_value_wall(var);
	y = var->r.drawstart - 1;
	while (++y < var->r.drawend)
	{
		d = y * 256 - WIN_X * 128 + (var->r.lineheight) * 128;
		var->t.texture_y = (d * var->t.h_texture) / (var->r.lineheight) / 256;
		if (var->t.texture_y >= 0)
		{
			i = (var->t.texture_y * var->t.w_texture + var->t.texture_x) * 4;
			color_r = var->t.texture[i + 2];
			color_g = var->t.texture[i + 1];
			color_b = var->t.texture[i];
			i = (y * WIN_X + x) * 4;
			if (i > 0 && i < (WIN_X * WIN_X * 4))
				mlx_pixel_put_to_image(var->mlx, x, y, \
										rgb_to_hexa(color_r, color_g, color_b));
		}
	}
}
