/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:36:10 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/05 16:19:10 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

#include <stdio.h>
void    ft_init(t_var *var)
{
		void *pt_texture;

		printf("%d\n",var->d.mlx == NULL );

        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/obj_pillier.xpm",
                        &var->t.w_texture1, &var->t.h_texture1);
        var->t.texture1 = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/chat.xpm",
                        &var->t.w_texture2, &var->t.h_texture2);
        var->t.texture2 = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/stone.xpm",
                        &var->t.w_texture3, &var->t.h_texture3);
        var->t.texture3 = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
        pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/wood.xpm",
                        &var->t.w_texture4, &var->t.h_texture4);
        var->t.texture4 = mlx_get_data_addr(pt_texture, &(var->d.bpp),
                        &(var->d.size_line), &(var->d.endian));
		pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/grass.xpm",
						&var->t.w_texture_floor, &var->t.h_texture_floor );
		var->t.texture_floor = mlx_get_data_addr(pt_texture, &(var->d.bpp),
						&(var->d.size_line), &(var->d.endian));
		pt_texture = mlx_xpm_file_to_image(var->d.mlx, "./texture/obj_pillier.xpm",
						&var->t.w_texture_obj, &var->t.h_texture_obj );
		var->t.texture_obj = mlx_get_data_addr(pt_texture, &(var->d.bpp),
						&(var->d.size_line), &(var->d.endian));

}

void ft_init_struct(t_var *var)
{
	var->d.posX = 22;
	var->d.posY = 12;
	var->d.dirX = -1;
	var->d.dirY = 0;
	var->d.planeX = 0;
	var->d.planeY = 0.66;
	var->d.time = 0;
	var->d.oldtime = 0;
	var->d.movespeed = 0.5;
	var->d.rotate = 0.2;
	var->d.oldDirX = 0;
	var->d.speed = 8;
	ft_init(var);
}
