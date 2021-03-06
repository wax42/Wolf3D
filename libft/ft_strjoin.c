/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:52:28 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/23 15:33:39 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	size_t	count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	final = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	count = 0;
	if (final == NULL)
		ft_exit(5);
	ft_strcpy(final, s1);
	ft_strcat(final, s2);
	return (final);
}
