/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:24:33 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 14:43:15 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_shooting2(t_var *var, void *point)
{
	if (var->r.shoot == 3)
	{
		point = mlx_xpm_file_to_image(var->mlx.mlx, "./t/pistol3.xpm",
			&var->t.w_pistol, &var->t.h_pistol);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp, \
					&(var->val), &(var->val));
	}
	if (var->r.shoot == 4)
	{
		point = mlx_xpm_file_to_image(var->mlx.mlx, "./t/pistol4.xpm",
			&var->t.w_pistol, &var->t.h_pistol);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp, \
				&(var->val), &(var->val));
	}
}

void	ft_shooting(t_var *var)
{
	void *point;

	if (var->r.shoot == 1)
	{
		point = mlx_xpm_file_to_image(var->mlx.mlx, "./t/pistol1.xpm",
			&var->t.w_pistol, &var->t.h_pistol);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp, \
					&(var->val), &(var->val));
	}
	if (var->r.shoot == 2)
	{
		point = mlx_xpm_file_to_image(var->mlx.mlx, "./t/pistol2.xpm",
			&var->t.w_pistol, &var->t.h_pistol);
		var->t.t_pistol = mlx_get_data_addr(point, &var->mlx.bpp, \
					&(var->val), &(var->val));
	}
	ft_shooting2(var, point);
	if (var->r.shoot > 4)
		var->r.shoot = 1;
}
