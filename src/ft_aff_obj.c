/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:10:41 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/17 12:23:01 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_tab *ft_dist_obj(t_lst_obj *lst, int len, t_var *var)
{
	t_tab 	*tab;
	int j;
	double spriteX;
	double spriteY;

	tab = (t_tab*)malloc(sizeof(t_tab) * (len));
	j = -1;
	while (++j < len)
	{
		tab[j].obj = lst;
		spriteX = ((double)(lst->coord.x) + 0.4 - var->d.posX) * var->d.dirX;
		spriteY = ((double)(lst->coord.y) + 0.4 - var->d.posY) * var->d.dirY;
		tab[j].dist = sqrt((spriteX * spriteX) + (spriteY * spriteY));
		lst = lst->next;
	}
	return (tab);
}

void 	ft_buble_sort_decrois(t_tab *tab, int len)
{
	int i;
	t_tab temp;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i].dist > tab[i + 1].dist)
			i++;
		else if (tab[i].dist < tab[i + 1].dist)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void ft_aff_obj(t_var *var)
{
	t_lst_obj *lst;
	t_tab 	*tab;
	int i;

	lst = var->lst;
	tab = ft_dist_obj(lst, var->nbr_elem, var);
	ft_buble_sort_decrois(tab, var->nbr_elem);
	i = -1;
	while (++i < var->nbr_elem)
		objet(var,  tab[i].obj->coord.y, tab[i].obj->coord.x);
	free(tab);
}
