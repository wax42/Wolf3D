/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 02:46:41 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 13:25:34 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_init_texture_sky_floor_obj(t_var *var, void *pt_texture)
{
	if (!(pt_texture = mlx_xpm_file_to_image(var->mlx.mlx, "./t/ceil4.xpm",
		&var->t.w_texture_floor, &var->t.h_texture_floor)))
		ft_exit(3);
	var->t.texture_floor = mlx_get_data_addr(pt_texture, &(var->mlx.bpp),
		&(var->mlx.size_line), &(var->mlx.endian));
	if (!(pt_texture = mlx_xpm_file_to_image(var->mlx.mlx, "./t/ceil2.xpm",
		&var->t.w_tex_sky, &var->t.h_tex_sky)))
		ft_exit(3);
	var->t.tex_sky = mlx_get_data_addr(pt_texture, &(var->mlx.bpp),
		&(var->mlx.size_line), &(var->mlx.endian));
	if (!(pt_texture = mlx_xpm_file_to_image(var->mlx.mlx, "./t/hitler",
		&var->t.w_texture_obj, &var->t.h_texture_obj)))
		ft_exit(3);
	var->t.texture_obj = mlx_get_data_addr(pt_texture, &(var->mlx.bpp),
		&(var->mlx.size_line), &(var->mlx.endian));
	if (!(var->r.start_menu = mlx_xpm_file_to_image(var->mlx.mlx, \
													"./t/start_menu.xpm",
		&var->t.w_tex_menu, &var->t.h_tex_menu)))
		ft_exit(3);
}

void	ft_init_texture(t_var *var)
{
	void *pt_texture;

	if (!(pt_texture = mlx_xpm_file_to_image(var->mlx.mlx, "./t/wall2h.xpm",
		&var->t.w_tex_mur_nord, &var->t.h_tex_mur_nord)))
		ft_exit(3);
	var->t.tex_mur_nord = mlx_get_data_addr(pt_texture, &(var->mlx.bpp),
		&(var->mlx.size_line), &(var->mlx.endian));
	if (!(pt_texture = mlx_xpm_file_to_image(var->mlx.mlx, "./t/wall3h.xpm",
		&var->t.w_tex_mur_sud, &var->t.h_tex_mur_sud)))
		ft_exit(3);
	var->t.tex_mur_sud = mlx_get_data_addr(pt_texture, &(var->mlx.bpp),
		&(var->mlx.size_line), &(var->mlx.endian));
	if (!(pt_texture = mlx_xpm_file_to_image(var->mlx.mlx, "./t/wall1h.xpm",
		&var->t.w_tex_mur_west, &var->t.h_tex_mur_west)))
		ft_exit(3);
	var->t.tex_mur_west = mlx_get_data_addr(pt_texture, &(var->mlx.bpp),
		&(var->mlx.size_line), &(var->mlx.endian));
	if (!(pt_texture = mlx_xpm_file_to_image(var->mlx.mlx, "./t/metal.xpm",
		&var->t.w_tex_mur_est, &var->t.h_tex_mur_est)))
		ft_exit(3);
	var->t.tex_mur_est = mlx_get_data_addr(pt_texture, &(var->mlx.bpp),
		&(var->mlx.size_line), &(var->mlx.endian));
	ft_init_texture_sky_floor_obj(var, pt_texture);
}
