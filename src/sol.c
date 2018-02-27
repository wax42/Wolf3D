/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:11 by wsabates          #+#    #+#             */
/*   Updated: 2018/02/27 17:13:21 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/wolf.h"


void	sol(t_var *var, int x, int y)
{
	y = var->d.drawEnd - 1;
	while (++y < WIN_Y)
		mlx_pixel_put_to_image(var->d, x, y, 0x666699);
}
