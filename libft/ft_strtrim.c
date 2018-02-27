/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:29:48 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/12 15:16:54 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t				i;
	size_t				len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	while (s[len] == 32 || s[len] == '\n' || s[len] == '\t')
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
