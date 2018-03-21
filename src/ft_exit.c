/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:32:05 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 16:21:13 by vguerand         ###   ########.fr       */
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
	exit(0);
}

int		ft_exit_click(void)
{
	exit(0);
}
