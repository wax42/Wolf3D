/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:10:41 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/14 06:30:29 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_tab *ft_dist_obj(t_lst_obj *lst, int len, int posX, int posY)
{
	t_tab 	*tab;
	int j;

	tab = (t_tab*)malloc(sizeof(t_tab) * (len));
	j = -1;
	while (++j < len)
	{
		tab[j].obj = lst;
		tab[j].dist =  ((posX - lst->coord.x) * (posX - lst->coord.x))  + ((posY - lst->coord.y) * (posY - lst->coord.y));
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

void 	ft_buble_sort_crois(t_tab *tab, int len)
{
	int i;
	t_tab temp;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i].dist < tab[i + 1].dist)
			i++;
		else if (tab[i].dist > tab[i + 1].dist)
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

#include <stdio.h>

void ft_aff_obj(t_var *var)
{
	t_lst_obj *lst;
	t_tab 	*tab;
	int i;

	lst = var->lst;
	tab = ft_dist_obj(lst, var->nbr_elem, (int)var->d.posX, (int)var->d.posY);
	if (var->d.side == 0 || var->d.side == 3)
	// if (var->d.dirX < 0.5 && var->d.dirX > -1.0 && var->d.dirY > -1.0 & var->d.dirY < 0.5)
		ft_buble_sort_crois(tab, var->nbr_elem);
	else
		ft_buble_sort_decrois(tab, var->nbr_elem);
	ft_putstr("SIDE   ");
	ft_putnbr(var->d.side);
	ft_putstr("\n");
	printf("dirX%f dirY%f\n", var->d.dirX, var->d.dirY);
	i = -1;
	while (++i < var->nbr_elem)
	{
		printf("%d %d %d\n", tab[i].obj->coord.x, tab[i].obj->coord.y, tab[i].dist);
		objet(var,  tab[i].obj->coord.y, tab[i].obj->coord.x);
	}
	free(tab);
}
