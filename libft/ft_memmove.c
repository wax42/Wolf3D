/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:19:07 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/13 12:12:21 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (source == dest)
		return (dst);
	if (source < dest)
	{
		source = (unsigned char*)src + len - 1;
		dest = dst + len - 1;
		while (len-- != 0)
			*dest-- = *source--;
	}
	else
	{
		while (len-- != 0)
			*dest++ = *source++;
	}
	return (dst);
}
