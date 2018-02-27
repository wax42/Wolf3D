/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:02:11 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/12 12:55:26 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*pc;
	size_t	i;

	pc = NULL;
	i = 0;
	pc = (char *)malloc(sizeof(*pc) * (len + 1));
	if (pc != NULL && s != NULL)
	{
		while (i < len)
		{
			pc[i] = s[start];
			start++;
			i++;
		}
		pc[i] = '\0';
	}
	return (pc);
}
