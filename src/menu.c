/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:14:14 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/17 15:58:04 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void ft_menu(t_var *var)
{
	if (var->d.menu_select == 0)
	{
		var->d.pistol = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/couteau.xpm",
					&var->t.w_tex_menu, &var->t.h_tex_menu );
		var->d.menu = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/menu_select.xpm",
					&var->t.w_tex_menu, &var->t.h_tex_menu);
	}
	if (var->d.menu_select == 1)
	{
		var->d.menu = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/menu_select1.xpm",
				&var->t.w_tex_menu, &var->t.h_tex_menu);
		var->d.pistol = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/pistolet.xpm",
				&var->t.w_tex_menu, &var->t.h_tex_menu );
	}
	if (var->d.menu_select == 2)
	{
		var->d.pistol = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/mitraillette.xpm",
				&var->t.w_tex_menu, &var->t.h_tex_menu );
		var->d.menu = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/menu_select2.xpm",
				&var->t.w_tex_menu, &var->t.h_tex_menu);
	}
	if (var->d.menu_select == 3)
	{
		var->d.pistol = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/pistol4.xpm",
				&var->t.w_tex_menu, &var->t.h_tex_menu );
		var->d.menu = mlx_xpm_file_to_image(var->mlx.mlx, "./texture/menu_select3.xpm",
				&var->t.w_tex_menu, &var->t.h_tex_menu );
	}
}
