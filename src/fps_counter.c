/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/06 01:32:27 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_fps_counter(t_var *var)
{
	char			*tmp;
	int 			bol;

	bol = 1;
	var->fps.old = var->fps.time1;
	gettimeofday(&var->fps.time1, NULL);
	if (var->fps.time1.tv_sec == var->fps.old.tv_sec)
	{
		var->fps.compt++;
		bol = 0;
	}
	tmp = ft_itoa((int)(var->fps.oldcompt));
	mlx_string_put(var->mlx.mlx, var->mlx.win, WIN_X / 100 + 700, WIN_Y / 100, \
		0xFF0000, "FPS:");
	mlx_string_put(var->mlx.mlx, var->mlx.win, WIN_X / 100 + 740, \
		WIN_Y / 100, 0xFF0000, tmp);
	free(tmp);
	if (bol)
	{
		var->fps.oldcompt = var->fps.compt;
		var->fps.compt = 0;
	}
}

void	ft_mlx_put_pixel_image_square(t_var *var, int x, int y, \
																	int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= var->r.denom)
	{
		j = -1;
		while (++j <= var->r.denom)
			mlx_pixel_put_to_image(var->mlx, x + i, y + j, color);
	}
}

void	ft_draw_map(t_var *var, int x, int y)
{
	if (var->parsing.tab[y][x] == 9)
		ft_mlx_put_pixel_image_square(\
			var, x * var->r.denom, y * var->r.denom, 0xFF00FF);
	if (var->parsing.tab[y][x] > 1 && var->parsing.tab[y][x] != 9)
		ft_mlx_put_pixel_image_square(\
			var, x * var->r.denom, y * var->r.denom, 0x000000);
	if (var->parsing.tab[y][x] == 1)
		ft_mlx_put_pixel_image_square(\
			var, x * var->r.denom, y * var->r.denom, 0xAAB2AC);
	if (((int)var->r.posx == x && (int)var->r.posy == y))
		ft_mlx_put_pixel_image_square(\
			var, x * var->r.denom, y * var->r.denom, 0xFF0000);
}

void	ft_put_map(t_var *var)
{
	int		x;
	int		y;
	t_coord p;
	t_coord p2;

	var->r.denom = ZOOM_MAP;
	y = -1;
	while (++y < var->parsing.max.y)
	{
		x = -1;
		while (++x < var->parsing.max.x)
			ft_draw_map(var, x, y);
	}
	p.x = floor(var->r.posx) * var->r.denom + 3;
	p.y = floor(var->r.posy) * var->r.denom + 3;
	p2.x = p.x + (var->r.diry - var->r.liney) * 20;
	p2.y = p.y - (var->r.dirx - var->r.linex) * 20;
	ft_ligne(var->mlx, p, p2, 0xFFFF00);
}
