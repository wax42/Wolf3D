/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:42:05 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/14 17:56:31 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c8;
	size_t			i;

	str = (unsigned char *)s;
	c8 = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == c8)
			return (str + i);
		i++;
	}
	return (NULL);
}
