/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:06:44 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 13:10:39 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_width_wall(t_var *var)
{
	if (var->r.side == 0 || var->r.side == 1)
		var->r.perpwalldist = ((double)var->r.mapx - var->r.posx +\
									(1 - var->r.stepx) / 2) / var->r.raydirx;
	else
		var->r.perpwalldist = ((double)var->r.mapy - var->r.posy +\
									(1 - var->r.stepy) / 2) / var->r.raydiry;
	if (var->r.perpwalldist == -0.0)
		var->r.perpwalldist = 0.5;
	var->r.lineheight = (int)(WIN_X / var->r.perpwalldist);
	var->r.drawstart = -var->r.lineheight / 2 + WIN_X / 2;
	if (var->r.drawstart < 0)
		var->r.drawstart = 0;
	var->r.drawend = var->r.lineheight / 2 + WIN_X / 2;
	if (var->r.drawend >= WIN_X)
		var->r.drawend = WIN_X - 1;
}

void	ft_find_side(t_var *var)
{
	if (var->r.sidedistx < var->r.sidedisty)
	{
		var->r.sidedistx += var->r.deltadistx;
		var->r.mapx += var->r.stepx;
		if (var->r.stepx == -1)
			var->r.side = 0;
		if (var->r.stepx == 1)
			var->r.side = 1;
	}
	else
	{
		var->r.sidedisty += var->r.deltadisty;
		var->r.mapy += var->r.stepy;
		if (var->r.stepy == -1)
			var->r.side = 2;
		if (var->r.stepy == 1)
			var->r.side = 3;
	}
}

void	ft_lancer_de_rayon(t_var *var)
{
	while (var->r.hit == 0)
	{
		ft_find_side(var);
		if ((var->r.mapx < var->parsing.max.x && var->r.mapx > 0) &&\
						(var->r.mapy < var->parsing.max.y && var->r.mapy > 0))
		{
			if (var->parsing.tab[var->r.mapx][var->r.mapy] > 1 && \
								var->parsing.tab[var->r.mapx][var->r.mapy] != 9)
				var->r.hit = 1;
			if (var->parsing.tab[var->r.mapx][var->r.mapy] == 3 && \
																var->r.del == 1)
				var->parsing.tab[var->r.mapx][var->r.mapy] = 1;
		}
		else
			var->r.hit = 1;
	}
}

void	ft_condtion_ray(t_var *var)
{
	if (var->r.raydirx < 0)
	{
		var->r.stepx = -1;
		var->r.sidedistx = (var->r.posx - (double)var->r.mapx) * \
			var->r.deltadistx;
	}
	else
	{
		var->r.stepx = 1;
		var->r.sidedistx = ((double)var->r.mapx + 1.0 - var->r.posx) * \
			var->r.deltadistx;
	}
	if (var->r.raydiry < 0)
	{
		var->r.stepy = -1;
		var->r.sidedisty = (var->r.posy - var->r.mapy) * var->r.deltadisty;
	}
	else
	{
		var->r.stepy = 1;
		var->r.sidedisty = (var->r.mapy + 1.0 - var->r.posy) * \
			var->r.deltadisty;
	}
}

void	ft_init_raycasting(t_var *var, int x)
{
	var->r.camerax = (2 * x / (double)WIN_X) - 1;
	var->r.raydirx = var->r.dirx + var->r.planex * var->r.camerax;
	var->r.raydiry = var->r.diry + var->r.planey * var->r.camerax;
	var->r.linex = var->r.raydirx;
	var->r.liney = var->r.raydiry;
	var->r.mapx = (int)var->r.posx;
	var->r.mapy = (int)var->r.posy;
	var->r.deltadistx = fabs(1 / var->r.raydirx);
	var->r.deltadisty = fabs(1 / var->r.raydiry);
	var->r.hit = 0;
	ft_condtion_ray(var);
}
