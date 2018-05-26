/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:37:30 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/24 22:52:32 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
