/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ligne.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:39:40 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/19 18:08:08 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static void		ft_ligne1(t_mlx mlx, t_ligne l, int color)
{
	int i;

	l.cumul = l.dx / 2;
	i = 0;
	while (i <= l.dx)
	{
		i++;
		l.x += l.xplus;
		l.cumul += l.dy;
		if (l.cumul >= l.dx)
		{
			l.cumul -= l.dx;
			l.y += l.yplus;
		}
		mlx_pixel_put_to_image(mlx, l.x, l.y, color);
	}
}

static void		ft_ligne2(t_mlx mlx, t_ligne l, int color)
{
	int i;

	l.cumul = l.dy / 2;
	i = 0;
	while (i <= l.dy)
	{
		i++;
		l.y += l.yplus;
		l.cumul += l.dx;
		if (l.cumul >= l.dy)
		{
			l.cumul -= l.dy;
			l.x += l.xplus;
		}
		mlx_pixel_put_to_image(mlx, l.x, l.y, color);
	}
}

void			ft_ligne(t_mlx mlx, t_coord p, t_coord p2, int color)
{
	t_ligne l;

	l.x = p.x;
	l.y = p.y;
	l.dx = p2.x - p.x;
	l.dy = p2.y - p.y;
	l.xplus = (l.dx > 0) ? 1 : -1;
	l.yplus = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	mlx_pixel_put_to_image(mlx, l.x, l.y, color);
	if (l.dx > l.dy)
		ft_ligne1(mlx, l, color);
	else
		ft_ligne2(mlx, l, color);
}
