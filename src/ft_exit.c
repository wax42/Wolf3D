/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:32:05 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/06 01:47:09 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_exit(int code)
{
	if (code == 0)
		ft_putendl("ERROR PARSING");
	else if (code == 1)
		ft_putendl("ERROR PARSING");
	else if (code == 3)
		ft_putendl("TEXTURE NOT VALID");
	else if (code == 4)
		ft_putendl("ERROR SIZE MAP");
	else if (code == 5)
		ft_putendl("ERROR MALLOC");
	exit(0);
}

int		ft_exit_click(void)
{
	exit(0);
}
