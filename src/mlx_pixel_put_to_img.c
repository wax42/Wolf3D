/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_to_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:36:22 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/01 02:10:46 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	mlx_pixel_put_to_image(t_draw draw, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	double		img_size;

	img_size = WIN_X * WIN_Y * draw.bpp / 8;
	if (x < 0 || y < 0 || y * draw.size_line + x * draw.bpp / 8 > \
		img_size
		|| x >= draw.size_line / (draw.bpp / 8) || y >= img_size / \
		draw.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = draw.bpp / 8;
	draw.map[y * draw.size_line + x * bit_pix] = color1;
	draw.map[y * draw.size_line + x * bit_pix + 1] = color2;
	draw.map[y * draw.size_line + x * bit_pix + 2] = color3;
}
