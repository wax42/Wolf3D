/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:52:40 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/23 15:28:45 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_tabint(int size_x, int size_y, int c)
{
	int **tab;
	int x;
	int y;

	if (!(tab = (int**)malloc(sizeof(int*) * size_y)))
		ft_exit(5);
	y = 0;
	while (y < size_y)
	{
		x = 0;
		if (!(tab[y] = (int*)malloc(sizeof(int) * size_x)))
			ft_exit(5);
		while (x < size_x)
		{
			tab[y][x] = c;
			x++;
		}
		y++;
	}
	return (tab);
}
