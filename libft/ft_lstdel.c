/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:45:48 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/14 17:41:12 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *nxt_list;

	list = *alst;
	while (list)
	{
		nxt_list = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nxt_list;
	}
	*alst = NULL;
}
