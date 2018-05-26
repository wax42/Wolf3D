/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mur.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:04 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/24 22:25:39 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		rgb_to_hexa(int r, int g, int b)
{
	return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
}

void	ft_texture_orientation(t_var *var, t_raycasting *r)
{
	if (r->side == 0)
	{
		r->texture = var->t.tex_mur_nord;
		r->w_texture = var->t.w_tex_mur_nord;
		r->h_texture = var->t.h_tex_mur_nord;
	}
	else if (r->side == 1)
	{
		r->texture = var->t.tex_mur_sud;
		r->w_texture = var->t.w_tex_mur_sud;
		r->h_texture = var->t.h_tex_mur_sud;
	}
	else if (r->side == 2)
	{
		r->texture = var->t.tex_mur_west;
		r->w_texture = var->t.w_tex_mur_west;
		r->h_texture = var->t.h_tex_mur_west;
	}
	else
	{
		r->texture = var->t.tex_mur_est;
		r->w_texture = var->t.w_tex_mur_est;
		r->h_texture = var->t.h_tex_mur_est;
	}
}

void	ft_value_wall(t_var *var, t_raycasting *r)
{
	if (r->side == 0 || r->side == 1)
		r->wallx = var->posy + r->perpwalldist * r->raydiry;
	else
		r->wallx = var->posx + r->perpwalldist * r->raydirx;
	r->wallx -= floor(r->wallx);
	r->texture_x = (int)(r->wallx * (double)r->w_texture);
	if (r->side == 0 && r->raydirx > 0)
		r->texture_x -= r->w_texture - 1;
	if (r->side == 1 && r->raydiry < 0)
		r->texture_x -= r->w_texture - 1;
}

void	mur(t_var *var, int x, t_raycasting *r)
{
	int y;
	int color_g;
	int color_b;
	int texture_y;
	int i;

	ft_texture_orientation(var, r);
	ft_value_wall(var, r);
	y = r->drawstart - 1;
	while (++y < r->drawend + 1)
	{
		i = y * 256 - WIN_Y * 128 + (r->lineheight) * 128;
		texture_y = (i * r->h_texture) / (r->lineheight) / 256;
		if (texture_y >= 0)
		{
			i = (texture_y * r->w_texture + r->texture_x) * 4;
			texture_y = r->texture[i + 2];
			color_g = r->texture[i + 1];
			color_b = r->texture[i];
			i = (y * WIN_Y + x) * 4;
			if (i > 0 && i < (WIN_Y * WIN_Y * 4))
				mlx_pixel_put_to_image(var->mlx, x, y, \
									rgb_to_hexa(texture_y, color_g, color_b));
		}
	}
}
