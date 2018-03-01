/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciel.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:43:23 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/01 17:51:07 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ciel(t_var *var, int x, int y)
{

	while (++y < var->d.drawStart)
		mlx_pixel_put_to_image(var->d, x, y, 0xFFFFFF + y);
}
