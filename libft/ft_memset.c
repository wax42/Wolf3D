/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:43:14 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/10 18:51:27 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t		i;
	char		*str;

	str = (char *)b;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
		str[i++] = c;
	return (b);
}
