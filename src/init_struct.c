/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:36:10 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/08 18:09:35 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_lst_obj	*add_obj(t_coord coord, t_lst_obj *tmp)
{
	t_lst_obj *header;

	if (!(header = (t_lst_obj*)malloc(sizeof(t_lst_obj))))
		ft_exit(5);
	header->coord = coord;
	header->next = tmp;
	return (header);
}

t_lst_obj	*ft_init_lst_obj(t_var *var)
{
	t_lst_obj	*tmp;
	t_coord		it;

	var->nbr_elem = 0;
	tmp = NULL;
	it.y = -1;
	while (++it.y < var->parsing.max.y)
	{
		it.x = -1;
		while (++it.x < var->parsing.max.x)
		{
			if (var->parsing.tab[it.y][it.x] == 9)
			{
				tmp = add_obj(it, tmp);
				var->nbr_elem++;
			}
		}
	}
	return (tmp);
}

void		ft_init_struct(t_var *var)
{
	var->key.up = 0;
	var->key.down = 0;
	var->key.left = 0;
	var->key.right = 0;
	var->posx = 0;
	var->posy = 0;
	ft_pos_spawn(var);
	var->del = 0;
	var->dirx = -1.0;
	var->diry = 0.0;
	var->planex = 0;
	var->planey = 0.66;
	var->fps.compt = 0;
	var->fps.oldcompt = 0;
	var->movespeed = 0.5;
	var->jump = 0;
	var->rotate = 0.2;
	var->olddirx = 0;
	var->speed = 8;
	var->lst = ft_init_lst_obj(var);
	ft_init_texture(var);
}
