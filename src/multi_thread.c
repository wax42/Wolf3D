/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:42:15 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 01:13:52 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"


#define PISTOLX 360
#define PISTOLY 680

void	mlx_put_image_to_image(t_var *var)
{
	int y;
	int x;
	int i;
	int color;

	x = 0;
	while (x++ < var->t.w_pistol - 10)
	{
		y = 0;
		while (++y < var->t.h_pistol)
		{
			i = (y * var->t.w_pistol + x) * 4;
			color = rgb_to_hexa(var->t.t_pistol[i + 2], var->t.t_pistol[i + 1],\
															var->t.t_pistol[i]);
			if (color != 9961608)
				mlx_pixel_put_to_image(var->mlx, x + PISTOLX, y + PISTOLY, \
																		color);
		}
	}
}

unsigned int	get_thread(pthread_t id, pthread_t threads[THREADS])
{
	int	i;

	i = -1;
	while (++i < THREADS && !pthread_equal(id, threads[i]))
		;
	return (i);
}

void	*ft_raycasting(void *data)
{
	int x;
	int	padding;
	int	start;
	t_var *var;
	t_raycasting r;

	var = (t_var*)data;
	padding = WIN_X / THREADS;
	start = padding * get_thread(pthread_self(), var->thread.core);
	// ft_putnbr(padding);
	ft_putendl("");
	ft_putnbr(start);
	// ft_putnbr(start);
	x = start - 1;
	// ft_putnbr(x);
	// ft_putendl("");
	while (++x < WIN_X && x < start + padding)
	{
		ft_init_raycasting(var, x, &r);
		ft_lancer_de_rayon(var, &r);
		ft_width_wall(var, &r);
		mur(var, x, &r);
		ft_floor(var, x, &r);
	}
	// ft_put_map(var);
	// ft_aff_obj(var);
	// ft_menu(var);
	// mlx_put_image_to_image(var);
	// mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->mlx.img, 0, 0);
	// mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->r.menu, 577, 735);
	// ft_fps_counter(var);
	return (NULL);
}

void			thread_start(t_var *var)
{
	int		i;

	i = -1;
	var->thread.get_core = -1;
	while (++i < THREADS)
	{
		pthread_create(&var->thread.core[i], NULL, &ft_raycasting, (void*)var);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(var->thread.core[i], NULL);
	ft_putendl("fini");
	ft_put_map(var);
	ft_aff_obj(var);
	ft_menu(var);
	mlx_put_image_to_image(var);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->mlx.img, 0, 0);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->menu, 577, 735);
	ft_fps_counter(var);
	ft_putendl("fini");
}
