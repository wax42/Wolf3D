/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:14:14 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 01:13:25 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_menu_selection(t_var *var, void *point)
{
	if (var->menu_select == 2)
	{
		if (!(point = mlx_xpm_file_to_image(var->mlx.mlx, "./t/pistolet.xpm",
			&var->t.w_pistol, &var->t.h_pistol)))
			ft_exit(3);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp, \
			&(var->val), &(var->val));
		if (!(var->menu = mlx_xpm_file_to_image(var->mlx.mlx, "./t/menu4.xpm",
			&var->t.w_tex_menu, &var->t.h_tex_menu)))
			ft_exit(3);
	}
	if (var->menu_select == 3)
	{
		if (!(point = mlx_xpm_file_to_image(var->mlx.mlx,\
													"./t/mitraillette.xpm",
			&var->t.w_pistol, &var->t.h_pistol)))
			ft_exit(3);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp, \
			&(var->val), &(var->val));
		if (!(var->menu = mlx_xpm_file_to_image(var->mlx.mlx, "./t/menu3.xpm",
				&var->t.w_tex_menu, &var->t.h_tex_menu)))
			ft_exit(3);
	}
}

void	ft_menu_selection1(t_var *var, void *point)
{
	if (var->menu_select == 1)
	{
		if (!(var->menu = mlx_xpm_file_to_image(var->mlx.mlx, "./t/menu1.xpm",
			&var->t.w_tex_menu, &var->t.h_tex_menu)))
			ft_exit(3);
		if (!(point = mlx_xpm_file_to_image(var->mlx.mlx, "./t/couteau.xpm",\
			&var->t.w_pistol, &var->t.h_pistol)))
			ft_exit(3);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp,\
			&(var->val), &(var->val));
	}
}

void	ft_menu(t_var *var)
{
	void *point;

	point = NULL;
	if (var->menu_select == 0)
	{
		if (!(point = mlx_xpm_file_to_image(var->mlx.mlx, "./t/pistol1.xpm",
			&var->t.w_pistol, &var->t.h_pistol)))
			ft_exit(3);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp,\
			&(var->val), &(var->val));
		if (!(var->menu = mlx_xpm_file_to_image(var->mlx.mlx, "./t/menu.xpm",
			&var->t.w_tex_menu, &var->t.h_tex_menu)))
			ft_exit(3);
		ft_shooting(var);
	}
	ft_menu_selection1(var, point);
	ft_menu_selection(var, point);
}
