/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:45:57 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/14 16:46:20 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;
	t_list *prev_elem;
	t_list *tmp_elem;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(elem = (t_list*)malloc(sizeof(t_list))) ||
			!(prev_elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	elem = f(lst);
	prev_elem = elem;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp_elem = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		tmp_elem = f(lst);
		prev_elem->next = tmp_elem;
		prev_elem = tmp_elem;
		lst = lst->next;
	}
	prev_elem->next = NULL;
	return (elem);
}
