/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 22:16:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/10 18:35:09 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		main(int argc, char **av)
{
	t_var var;

	if (argc == 2)
		var.parsing.tab = parsing(&var.parsing, av[1]);
	var.d.mlx = mlx_init();
	ft_init_struct(&var);
	var.d.win = mlx_new_window(var.d.mlx, WIN_X, WIN_Y, "Wolf3d");
	var.d.img = mlx_new_image(var.d.mlx, WIN_X, WIN_Y);
	var.d.map = mlx_get_data_addr(var.d.img, &var.d.bpp, \
		&var.d.size_line, &var.d.endian);
	ft_raycasting(&var);
	mlx_hook(var.d.win, 2, (1L << 0), my_key_funct, &var);
	mlx_hook(var.d.win, 17, 0, ft_exit_click, &var);
	mlx_loop(var.d.mlx);
}
