/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 22:16:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/16 17:41:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		main(int argc, char **av)
{
	t_var var;

	if (argc == 2)
		var.parsing.tab = parsing(&var.parsing, av[1]);
	var.mlx.mlx = mlx_init();
	ft_init_struct(&var);
	var.mlx.win = mlx_new_window(var.mlx.mlx, WIN_X, WIN_Y, "Wolf3d");
	var.mlx.img = mlx_new_image(var.mlx.mlx, WIN_X, WIN_Y);
	var.mlx.map = mlx_get_data_addr(var.mlx.img, &var.mlx.bpp, \
		&var.mlx.size_line, &var.mlx.endian);
	ft_raycasting(&var);
	mlx_hook(var.mlx.win, 2, (1L << 0), my_key_funct, &var);
	mlx_hook(var.mlx.win, 17, 0, ft_exit_click, &var);
	mlx_loop_hook(var.mlx.mlx, (int(*)())ft_raycasting, &var);
	mlx_loop(var.mlx.mlx);
}
