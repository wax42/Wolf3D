/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:52:40 by vguerand          #+#    #+#             */
/*   Updated: 2017/12/12 22:53:26 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_tabint(int size_x, int size_y, int c)
{
	int **tab;
	int x;
	int y;

	tab = (int**)malloc(sizeof(int*) * size_y);
	y = 0;
	while (y < size_y)
	{
		x = 0;
		tab[y] = (int*)malloc(sizeof(int) * size_x);
		while (x < size_y)
		{
			tab[y][x] = c;
			x++;
		}
		y++;
	}
	return (tab);
}
