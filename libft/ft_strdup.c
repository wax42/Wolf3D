/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:49:39 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/23 15:32:48 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *pc;

	if (!(pc = (char *)malloc(sizeof(*pc) * (ft_strlen(s1) + 1))))
		ft_exit(5);
	ft_strcpy(pc, s1);
	return (pc);
}
