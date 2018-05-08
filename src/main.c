/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 22:16:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 01:17:26 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		ft_key_press(int keycode, t_var *var)
{
	keycode = var->key.up;
	return (keycode);
}

int		ft_key_release(int keycode, t_var *var)
{
	keycode = var->key.up;
	return (keycode);
}

int		main(int argc, char **av)
{
	t_var var;

	if (argc == 2)
		var.parsing.tab = parsing(&var.parsing, av[1]);
	else
	{
		ft_putstr("Usage : ./Wolf3d map.txt\n");
		return (0);
	}
	var.mlx.mlx = mlx_init();
	ft_init_struct(&var);
	var.mlx.win = mlx_new_window(var.mlx.mlx, WIN_X, WIN_Y, "Wolf3d");
	var.mlx.img = mlx_new_image(var.mlx.mlx, WIN_X, WIN_Y);
	var.mlx.map = mlx_get_data_addr(var.mlx.img, &var.mlx.bpp, \
		&var.mlx.size_line, &var.mlx.endian);
	thread_start(&var);
	mlx_hook(var.mlx.win, 2, 1, ft_key_press, &var);
    mlx_hook(var.mlx.win, 3, 2, ft_key_release, &var);
	mlx_hook(var.mlx.win, 2, (1L << 0), my_key_funct, &var);
	mlx_hook(var.mlx.win, 17, 0, ft_exit_click, &var);
	mlx_hook(var.mlx.win, 6, (1L << 6), mouse_hook, &var);
	mlx_loop_hook(var.mlx.mlx, (int(*)())thread_start, &var);
	mlx_loop(var.mlx.mlx);
	return (0);
}
