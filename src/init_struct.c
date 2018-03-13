/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:36:10 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/13 13:55:28 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

#include <stdio.h>

void	ft_change_tex(t_var *var)
{
	void *pt_texture;

	mlx_destroy_image(var->d.mlx, var->d.img);
	var->d.mlx = mlx_init();
	pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/Swastika.xpm",
					&var->t.w_tex_mur_nord, &var->t.h_tex_mur_nord);
	var->t.tex_mur_nord = mlx_get_data_addr(pt_texture, &(var->d.bpp),
					&(var->d.size_line), &(var->d.endian));
	var->d.img = mlx_new_image(var->d.mlx, WIN_X, WIN_Y);
	var->d.map = mlx_get_data_addr(var->d.img, &var->d.bpp, \
		&var->d.size_line, &var->d.endian);
	ft_raycasting(var);
}

void    ft_init(t_var *var)
{
		void *pt_texture;

        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/wood.xpm",
                        &var->t.w_tex_mur_nord, &var->t.h_tex_mur_nord);
        var->t.tex_mur_nord = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/chat.xpm",
                        &var->t.w_tex_mur_sud, &var->t.h_tex_mur_sud);
        var->t.tex_mur_sud = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/stone.xpm",
                        &var->t.w_tex_mur_west, &var->t.h_tex_mur_west);
        var->t.tex_mur_west = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/brick.xpm",
                        &var->t.w_tex_mur_est, &var->t.h_tex_mur_est);
        var->t.tex_mur_est = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
		pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/grass.xpm",
						&var->t.w_texture_floor, &var->t.h_texture_floor );
		var->t.texture_floor = mlx_get_data_addr(pt_texture, &(var->d.bpp),
						&(var->d.size_line), &(var->d.endian));
		pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/metal.xpm",
						&var->t.w_tex_sky, &var->t.h_tex_sky );
		var->t.tex_sky = mlx_get_data_addr(pt_texture, &(var->d.bpp),
						&(var->d.size_line), &(var->d.endian));
		pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/soldat.xpm",
						&var->t.w_texture_obj, &var->t.h_texture_obj );
		var->t.texture_obj = mlx_get_data_addr(pt_texture, &(var->d.bpp),
						&(var->d.size_line), &(var->d.endian));
}

t_lst_obj *add_obj(t_coord coord, t_lst_obj *tmp)
{
	t_lst_obj *header;

	header = (t_lst_obj*)malloc(sizeof(t_lst_obj));
	header->coord = coord;
	header->next = tmp;
	return (header);
}

t_lst_obj *ft_init_lst_obj(t_var *var)
{
	t_lst_obj *tmp;
	t_coord it;

	var->nbr_elem = 0;
	tmp = NULL;
	it.y = -1;
	while (++it.y < var->parsing.max.y)
	{
		it.x = -1;
		while (++it.x < var->parsing.max.x)
		{
			if (var->parsing.tab[it.y][it.x] == 9) // OBJ
			{
				tmp = add_obj(it, tmp);
				var->nbr_elem++;
			}
		}
	}
	return (tmp);
}

void ft_init_struct(t_var *var)
{
	var->d.del = 0;
	var->d.del_wall = 1;
	var->d.posX = 22;
	var->d.posY = 11;
	var->d.dirX = -1.0;
	var->d.dirY = 0.0;
	var->d.planeX = 0;
	var->d.planeY = 0.66;
	var->d.time = 0;
	var->d.oldtime = 0;
	var->d.movespeed = 0.5;
	var->d.rotate = 0.2;
	var->d.oldDirX = 0;
	var->d.speed = 8;
	var->lst = ft_init_lst_obj(var);
	ft_init(var);
}
