/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:37:28 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/15 08:38:54 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_remplissage(char **tab_rt, char *str, int i, char c)
{
	int		j;
	int		index;

	j = 0;
	index = ft_index_mot(str, i, c);
	while (str[index] != c && str[index])
	{
		tab_rt[i][j] = str[index];
		index++;
		j++;
	}
	tab_rt[i][j] = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab_rt;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	i = 0;
	if (!(tab_rt = (char**)malloc(sizeof(char*) * (ft_nb_mots(str, c) + 1))))
		return (NULL);
	while (i < ft_nb_mots(str, c))
	{
		tab_rt[i] = (char*)malloc(sizeof(char) * (ft_nb_ltr(str, i, c) + 1));
		if (tab_rt[i] == NULL)
			return (NULL);
		ft_remplissage(tab_rt, str, i, c);
		i++;
	}
	tab_rt[i] = NULL;
	return (tab_rt);
}
