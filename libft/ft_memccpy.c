/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:15:08 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/10 19:26:07 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	i = 0;
	dest = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	while (i < n)
	{
		dest[i] = srcs[i];
		if (srcs[i] == (unsigned char)c)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
