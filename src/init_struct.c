/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:36:10 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 14:31:52 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_lst_obj	*add_obj(t_coord coord, t_lst_obj *tmp)
{
	t_lst_obj *header;

	header = (t_lst_obj*)malloc(sizeof(t_lst_obj));
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
	ft_pos_spawn(var);
	var->r.del = 0;
	var->r.del_wall = 1;
	var->r.dirx = -1.0;
	var->r.diry = 0.0;
	var->r.planex = 0;
	var->r.planey = 0.66;
	var->fps.time = 0;
	var->fps.oldtime = 0;
	var->r.movespeed = 0.5;
	var->r.rotate = 0.2;
	var->r.olddirx = 0;
	var->r.speed = 8;
	var->lst = ft_init_lst_obj(var);
	ft_init_texture(var);
}
