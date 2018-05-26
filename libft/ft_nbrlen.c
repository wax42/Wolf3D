/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:11:24 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/07 23:15:10 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int i)
{
	char *str;

	str = ft_itoa(i);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}
