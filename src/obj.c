/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:21:08 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 00:54:58 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		ft_lancer_d_obj(t_var *var, t_raycasting *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
		}
		if (r->mapx < var->parsing.max.x && r->mapx >= 0 && r->mapy\
			< var->parsing.max.y && r->mapy >= 0)
		{
			if (r->mapx == var->o.coord.x && r->mapy == var->o.coord.y)
				return (1);
			else if (var->parsing.tab[r->mapy][r->mapx] > 1 &&\
				var->parsing.tab[r->mapy][r->mapx] != 9)
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int		obj_check(t_var *var, int x, t_raycasting *r)
{
	var->camerax = (2 * x / (double)WIN_X) - 1;
	r->raydirx = var->dirx + var->planex * var->camerax;
	r->raydiry = var->diry + var->planey * var->camerax;
	r->mapx = (int)var->posx;
	r->mapy = (int)var->posy;
	r->deltadistx = fabs(1 / r->raydirx);
	r->deltadisty = fabs(1 / r->raydiry);
	r->hit = 0;
	ft_condtion_ray(var, r);
	return (ft_lancer_d_obj(var, r));
}

void	ft_draw_obj(t_var *var, int x, int y)
{
	int color;
	int i;

	if (var->t.texture_y > 0)
	{
		i = (var->t.texture_y * var->t.w_texture_obj + \
									var->t.texture_x) * 4;
		color = rgb_to_hexa(var->t.texture_obj[i + 2], \
							var->t.texture_obj[i + 1], var->t.texture_obj[i]);
		i = (y * WIN_X + x) * 4;
		if (i > 0 && i < (WIN_X * WIN_X * 4) && (color != 9961608))
			mlx_pixel_put_to_image(var->mlx, x, y, color);
	}
}

void	objet(t_var *var, int x, int y)
{
	t_raycasting r;
	int d;

	ft_init_obj(var, x, y);
	x = var->o.drawstartx;
	while (x++ < var->o.drawendx)
	{
		var->t.texture_x = (int)(256 * (x - (-var->o.spritewidth / 2 + \
	var->o.spritescreenx)) * var->t.w_texture_obj / var->o.spritewidth) / 256;
		y = var->o.drawstarty;
		if (obj_check(var, x, &r))
		{
			if (var->o.transformy > 0 && x > 0 && x < WIN_X)
				while (++y < var->o.drawendy)
				{
					d = ((y - var->vmovescreen) * 256 - WIN_Y * 128 + \
						var->o.spriteheight * 128);
					var->t.texture_y = ((d * var->t.h_texture_obj) / \
													var->o.spriteheight) / 256;
					ft_draw_obj(var, x, y);
				}
		}
	}
}
