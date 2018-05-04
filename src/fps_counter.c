/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/04 19:02:00 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_fps_counter(t_var *var)
{
	struct timeval	tp;
	char			*tmp;

	var->fps.oldtime = var->fps.time;
	gettimeofday(&tp, NULL);
	var->fps.time = tp.tv_usec;
	var->fps.frametime = round((var->fps.time - var->fps.oldtime) / 1000);
	if (var->fps.frametime < 0)
		ft_fps_counter(var);
	tmp = ft_itoa((int)var->fps.frametime);
	mlx_string_put(var->mlx.mlx, var->mlx.win, WIN_X / 100 + 700, WIN_Y / 100, \
		0xFF0000, "FPS:");
	mlx_string_put(var->mlx.mlx, var->mlx.win, WIN_X / 100 + 740, \
		WIN_Y / 100, 0xFF0000, tmp);
	free(tmp);
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
	p2.x = p.x + (var->r.linex - var->r.dirx) * 20;
	p2.y = p.y - (var->r.liney - var->r.diry) * 20;
	ft_ligne(var->mlx, p, p2, 0xFFFF00);
	p.x = floor(var->r.posx) * var->r.denom + 4;
	p.y = floor(var->r.posy) * var->r.denom + 3;
	p2.x = p.x + (var->r.linex - var->r.dirx) * 20;
	p2.y = p.y - (var->r.liney - var->r.diry) * 20;
	ft_ligne(var->mlx, p, p2, 0xFFFF00);
}
