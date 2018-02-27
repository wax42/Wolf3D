/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:17:22 by wsabates          #+#    #+#             */
/*   Updated: 2018/02/20 13:48:26 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	fps_counter(t_var *var)
{
	struct timeval	tp;
	char			*tmp;
	
	var->d.oldtime = var->d.time;
	gettimeofday(&tp, NULL);
	var->d.time = tp.tv_usec;
	gettimeofday(&tp, NULL);
	var->d.time = tp.tv_usec;
	var->d.frametime = round((var->d.time - var->d.oldtime) / 1000);
	if (var->d.frametime < 0)
		fps_counter(var);
	tmp = ft_itoa((int)var->d.frametime);
	mlx_string_put(var->d.init, var->d.win, WIN_X / 100, WIN_Y / 100, \
		0xFF0000, "FPS:");
	mlx_string_put(var->d.init, var->d.win, WIN_X / 100 + 40, \
		WIN_Y / 100, 0xFF0000, tmp);
	free(tmp);
	var->d.movespeed = var->d.frametime * var->d.speed;
	var->d.rotspeed = var->d.frametime * 0.003;
}
