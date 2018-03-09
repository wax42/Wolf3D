/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_mots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 08:35:23 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/15 08:36:38 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_mots(char *str, char separateur)
{
	int		i;
	int		nb_mots;

	i = 0;
	nb_mots = 0;
	while (str[i])
	{
		if (str[i] == separateur)
			i++;
		else
		{
			while (str[i] != separateur && str[i])
				i++;
			nb_mots++;
		}
	}
	return (nb_mots);
}
