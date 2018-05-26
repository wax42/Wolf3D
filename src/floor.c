/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:11 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 00:33:08 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	calculate_floor(t_var *var, t_raycasting *r)
{
	r->f.weight = (r->currentdist - r->f.distplayer) / \
									(r->distwall - r->f.distplayer);
	r->f.current_x = r->f.weight * r->f.wallx +\
										(1.0 - r->f.weight) * var->posx;
	r->f.current_y = r->f.weight * r->f.wally + \
										(1.0 - r->f.weight) * var->posy;
	r->f.tex_x = (int)(r->f.current_x * \
							var->t.w_texture_floor) % var->t.w_texture_floor;
	r->f.tex_y = (int)(r->f.current_y * \
							var->t.h_texture_floor) % var->t.h_texture_floor;
}

void	floor_find_side(t_raycasting *r)
{
	if ((r->side == 0 || r->side == 1) && r->raydirx > 0)
	{
		r->f.wallx = r->mapx;
		r->f.wally = r->mapy + r->wallx;
	}
	else if ((r->side == 0 || r->side == 1) && r->raydirx < 0)
	{
		r->f.wallx = r->mapx + 1.0;
		r->f.wally = r->mapy + r->wallx;
	}
	else if ((r->side == 2 || r->side == 3) && r->raydiry > 0)
	{
		r->f.wallx = r->mapx + r->wallx;
		r->f.wally = r->mapy;
	}
	else
	{
		r->f.wallx = r->mapx + r->wallx;
		r->f.wally = r->mapy + 1.0;
	}
	r->distwall = r->perpwalldist;
	r->f.distplayer = 0.0;
	if (r->drawend < 0)
		r->drawend = WIN_Y;
}

void	ft_floor(t_var *var, int x, t_raycasting *r)
{
	int y;
	int i;
	int color_g;
	int color_b;
	int color_r;

	floor_find_side(r);
	y = r->drawend - 1;
	while (y++ < WIN_Y)
	{
		r->currentdist = WIN_Y / (2.0 * y - WIN_Y);
		calculate_floor(var, r);
		i = (var->t.w_texture_floor * r->f.tex_y + \
													r->f.tex_x) * 4;
		color_r = var->t.texture_floor[i + 2];
		color_g = var->t.texture_floor[i + 1];
		color_b = var->t.texture_floor[i];
		mlx_pixel_put_to_image(var->mlx, x, y, \
										rgb_to_hexa(color_r, color_g, color_b));
		color_r = var->t.tex_sky[i + 2];
		color_g = var->t.tex_sky[i + 1];
		color_b = var->t.tex_sky[i];
		mlx_pixel_put_to_image(var->mlx, x, WIN_Y - y, \
										rgb_to_hexa(color_r, color_g, color_b));
	}
}
