/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 00:37:47 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_fps_counter(t_var *var)
{
	char			*tmp;
	int				bol;

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
	int	x1;
	int	y1;

	x1 = -1;
	while (++x1 <= var->map.size_x)
	{
		y1 = -1;
		while (++y1 <= var->map.size_y)
			mlx_pixel_put_to_image(var->mlx, x + x1, y + y1, color);
	}
}

void	ft_draw_map(t_var *var, int x, int y)
{
	if (var->parsing.tab[y][x] == 9)
		ft_mlx_put_pixel_image_square(\
			var, x * var->map.size_x, y * var->map.size_y, COLOR_OBJ);
	if (var->parsing.tab[y][x] > 1 && var->parsing.tab[y][x] != 9)
		ft_mlx_put_pixel_image_square(\
			var, x * var->map.size_x, y * var->map.size_y, COLOR_WALL);
	if (var->parsing.tab[y][x] == 1)
		ft_mlx_put_pixel_image_square(\
			var, x * var->map.size_x, y * var->map.size_y, COLOR_FLOOR);
	if (((int)var->posx == x && (int)var->posy == y))
		ft_mlx_put_pixel_image_square(\
			var, x * var->map.size_x, y * var->map.size_y, COLOR_PERSO);
}

void	ft_put_map(t_var *var)
{
	int		x;
	int		y;
	int		max;
	t_coord p;
	t_coord p2;

	(var->parsing.max.y < var->parsing.max.x) ? (max = var->parsing.max.x) : (max = var->parsing.max.y);
	var->map.size_x = ZOOM_MAP_X  / var->parsing.max.x;
	var->map.size_y = ZOOM_MAP_Y / var->parsing.max.y;
	y = -1;
	while (++y < var->parsing.max.y)
	{
		x = -1;
		while (++x < var->parsing.max.x)
			ft_draw_map(var, x, y);
	}
	p.x = floor(var->posx) * var->map.size_x + var->map.size_x / 2;
	p.y = floor(var->posy) * var->map.size_y + var->map.size_y / 2;
	p2.x = p.x + (var->diry - var->liney) * SIZE_LINE;
	p2.y = p.y - (var->dirx - var->linex) * SIZE_LINE;
	ft_ligne(var->mlx, p, p2, COLOR_LINE);
}
