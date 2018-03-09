/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_mot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:50:28 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/15 08:31:26 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_index_mot(char *str, int mot, char separateur)
{
	int		i;
	int		compteur_mots;

	i = 0;
	compteur_mots = 0;
	while (str[i])
	{
		while (str[i] == separateur)
			i++;
		if (compteur_mots == mot)
			return (i);
		while (str[i] != separateur && str[i])
			i++;
		compteur_mots++;
	}
	return (0);
}
