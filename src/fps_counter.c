/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 13:08:40 by wsabates         ###   ########.fr       */
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

	i = 0;
	while (i++ <= var->r.denom)
	{
		j = 0;
		while (j++ <= var->r.denom)
			mlx_pixel_put_to_image(var->mlx, x + i, y + j, color);
	}
}

void	ft_draw_map(t_var *var, int i, int j)
{
	if (var->parsing.tab[j][i] == 9)
		ft_mlx_put_pixel_image_square(\
			var, i * var->r.denom, j * var->r.denom, 0xFF00FF);
	if (var->parsing.tab[j][i] > 1 && var->parsing.tab[j][i] != 9)
		ft_mlx_put_pixel_image_square(\
			var, i * var->r.denom, j * var->r.denom, 0x000000);
	if (var->parsing.tab[j][i] == 1)
		ft_mlx_put_pixel_image_square(\
			var, i * var->r.denom, j * var->r.denom, 0xAAB2AC);
	if (((int)var->r.posx == j && (int)var->r.posy == i))
		ft_mlx_put_pixel_image_square(\
			var, i * var->r.denom, j * var->r.denom, 0xFF0000);
}

void	ft_put_map(t_var *var)
{
	int		i;
	int		j;
	t_coord p;
	t_coord p2;

	var->r.denom = ZOOM_MAP;
	i = -1;
	while (++i < var->parsing.max.y)
	{
		j = -1;
		while (++j < var->parsing.max.x)
		{
			ft_draw_map(var, i, j);
		}
	}
	p.x = floor(var->r.posy) * var->r.denom + 3;
	p.y = floor(var->r.posx) * var->r.denom + 3;
	p2.x = p.x + (var->r.linex - var->r.dirx) * 20;
	p2.y = p.y - (var->r.liney - var->r.diry) * 20;
	ft_ligne(var->mlx, p, p2, 0xFFFF00);
	p.x = floor(var->r.posy) * var->r.denom + 4;
	p.y = floor(var->r.posx) * var->r.denom + 3;
	p2.x = p.x + (var->r.linex - var->r.dirx) * 20;
	p2.y = p.y - (var->r.liney - var->r.diry) * 20;
	ft_ligne(var->mlx, p, p2, 0xFFFF00);
}
