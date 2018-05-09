/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:06:44 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/09 04:45:13 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_width_wall(t_var *var, t_raycasting *r)
{
	if (r->side == 0 || r->side == 1)
		r->perpwalldist = ((double)r->mapx - var->posx +\
									(1 - r->stepx) / 2) / r->raydirx;
	else
		r->perpwalldist = ((double)r->mapy - var->posy +\
									(1 - r->stepy) / 2) / r->raydiry;
	if (r->perpwalldist == -0.0)
		r->perpwalldist = 0.5;
	r->lineheight = (int)(WIN_Y / r->perpwalldist);
	r->drawstart = -r->lineheight / 2 + WIN_Y / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + WIN_Y / 2;
	if (r->drawend >= WIN_Y)
		r->drawend = WIN_Y - 1;
}

void	ft_find_side(t_raycasting *r)
{
	if (r->sidedistx < r->sidedisty)
	{
		r->sidedistx += r->deltadistx;
		r->mapx += r->stepx;
		if (r->stepx == -1)
			r->side = 0;
		if (r->stepx == 1)
			r->side = 1;
	}
	else
	{
		r->sidedisty += r->deltadisty;
		r->mapy += r->stepy;
		if (r->stepy == -1)
			r->side = 2;
		if (r->stepy == 1)
			r->side = 3;
	}
}

void	ft_lancer_de_rayon(t_var *var, t_raycasting *r)
{
	while (r->hit == 0)
	{
		ft_find_side(r);
		if ((r->mapx < var->parsing.max.x && r->mapx > 0) &&\
						(r->mapy < var->parsing.max.y && r->mapy > 0))
		{
			if (var->parsing.tab[r->mapy][r->mapx] > 1 && \
								var->parsing.tab[r->mapy][r->mapx] != 9)
				r->hit = 1;
		}
		else
			r->hit = 1;
	}
}

void	ft_condtion_ray(t_var *var, t_raycasting *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (var->posx - (double)r->mapx) * \
			r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = ((double)r->mapx + 1.0 - var->posx) * \
			r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (var->posy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - var->posy) * \
			r->deltadisty;
	}
}

void	ft_init_raycasting(t_var *var, int x, t_raycasting *r)
{
	var->camerax = (2 * x / (double)WIN_X) - 1;
	r->raydirx = var->dirx + var->planex * var->camerax;
	r->raydiry = var->diry + var->planey * var->camerax;
	if (r->curent_thread == THREADS - 1)
	{
		var->map.linex = r->raydirx;
		var->map.liney = r->raydiry;
	}
	r->mapx = (int)var->posx;
	r->mapy = (int)var->posy;
	r->deltadistx = fabs(1 / r->raydirx);
	r->deltadisty = fabs(1 / r->raydiry);
	r->hit = 0;
	ft_condtion_ray(var, r);
}
