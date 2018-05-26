/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_search_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:39:31 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/25 00:57:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_search_index(t_list *lst, size_t index)
{
	while (lst)
	{
		if (lst->index == index)
			return (lst);
	}
	return (NULL);
}
