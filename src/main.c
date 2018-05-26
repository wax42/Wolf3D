/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 22:16:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/12 17:18:02 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_key_commands(t_var *var, int keycode)
{
	if (keycode == K_ESC)
		exit(1);
	if (keycode == K_Y)
		(var->key.pistol) ? (var->key.pistol *= 0) : (var->key.pistol++);
	if (keycode == K_M)
		var->key.mouse = 1;
	if (keycode == K_N)
		var->key.mouse = 0;
}

int		ft_key_press(int keycode, t_var *var)
{
	ft_key_commands(var, keycode);
	if (keycode == K_D_MOVE_RIGHT || keycode == K_ARROW_RIGHT)
		var->key.right = 1;
	if (keycode == K_A_MOVE_LEFT || keycode == K_ARROW_LEFT)
		var->key.left = 1;
	if (keycode == K_S_MOVE_DOWN || keycode == K_ARROW_DOWM)
		var->key.down = 1;
	if (keycode == K_W_MOVE_UP || keycode == K_ARROW_UP)
		var->key.up = 1;
	if (keycode == K_Q_LOOK_LEFT)
		var->key.look_left = 1;
	if (keycode == K_E_LOOK_RIGHT)
		var->key.look_right = 1;
	return (keycode);
}

int		ft_key_release(int keycode, t_var *var)
{
	if (keycode == K_D_MOVE_RIGHT || keycode == K_ARROW_RIGHT)
		var->key.right = 0;
	if (keycode == K_A_MOVE_LEFT || keycode == K_ARROW_LEFT)
		var->key.left = 0;
	if (keycode == K_S_MOVE_DOWN || keycode == K_ARROW_DOWM)
		var->key.down = 0;
	if (keycode == K_W_MOVE_UP || keycode == K_ARROW_UP)
		var->key.up = 0;
	if (keycode == K_Q_LOOK_LEFT)
		var->key.look_left = 0;
	if (keycode == K_E_LOOK_RIGHT)
		var->key.look_right = 0;
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
	mlx_hook(var.mlx.win, 17, 0, ft_exit_click, &var);
	mlx_hook(var.mlx.win, 6, (1L << 6), mouse_hook, &var);
	mlx_loop_hook(var.mlx.mlx, (int(*)())thread_start, &var);
	mlx_loop(var.mlx.mlx);
	return (0);
}
