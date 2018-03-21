/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:21:08 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/21 13:16:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		ft_lancer_d_obj(t_var *var)
{
	while (var->r.hit == 0)
	{
		if (var->r.sidedistx < var->r.sidedisty)
		{
			var->r.sidedistx += var->r.deltadistx;
			var->r.mapx += var->r.stepx;
		}
		else
		{
			var->r.sidedisty += var->r.deltadisty;
			var->r.mapy += var->r.stepy;
		}
		if (var->r.mapx < var->parsing.max.x && var->r.mapx >= 0 && var->r.mapy\
			< var->parsing.max.y && var->r.mapy >= 0)
		{
			if (var->r.mapx == var->o.coord.x && var->r.mapy == var->o.coord.y)
				return (1);
			else if (var->parsing.tab[var->r.mapx][var->r.mapy] > 1 &&\
				var->parsing.tab[var->r.mapx][var->r.mapy] != 9)
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int		obj_check(t_var *var, int x)
{
	var->r.camerax = (2 * x / (double)WIN_X) - 1;
	var->r.raydirx = var->r.dirx + var->r.planex * var->r.camerax;
	var->r.raydiry = var->r.diry + var->r.planey * var->r.camerax;
	var->r.mapx = (int)var->r.posx;
	var->r.mapy = (int)var->r.posy;
	var->r.deltadistx = fabs(1 / var->r.raydirx);
	var->r.deltadisty = fabs(1 / var->r.raydiry);
	var->r.hit = 0;
	ft_condtion_ray(var);
	return (ft_lancer_d_obj(var));
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
	int d;

	ft_init_obj(var, x, y);
	x = var->o.drawstartx;
	while (x++ < var->o.drawendx)
	{
		var->t.texture_x = (int)(256 * (x - (-var->o.spritewidth / 2 + \
	var->o.spritescreenx)) * var->t.w_texture_obj / var->o.spritewidth) / 256;
		y = var->o.drawstarty;
		if (obj_check(var, x))
		{
			if (var->o.transformy > 0 && x > 0 && x < WIN_X && \
				var->o.transformy < var->parsing.tab[var->r.mapx][var->r.mapy])
				while (++y < var->o.drawendy)
				{
					d = ((y - var->s.vmovescreen) * 256 - WIN_Y * 128 + \
						var->o.spriteheight * 128);
					var->t.texture_y = ((d * var->t.h_texture_obj) / \
													var->o.spriteheight) / 256;
					ft_draw_obj(var, x, y);
				}
		}
	}
}
