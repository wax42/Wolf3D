/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:37:34 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/25 01:00:32 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_split		*ft_lstnew_split(char *str, int index, int c)
{
	t_split	*tmp;
	int		n;

	if (!(tmp = (t_split*)malloc(sizeof(t_split))))
		return (NULL);
	n = 0;
	while (str[index] != c && str[index])
	{
		index++;
		n++;
	}
	tmp->content = ft_strsub(str, index - n, n);
	tmp->content_size = n;
	return (tmp);
}

t_split				*ft_lstsplit(char *str, int c)
{
	int		i;
	t_split	*header;
	t_split	*lst;
	t_split *tmp;
	int		index;

	i = 0;
	index = 0;
	while (str[index] == c && str[index])
		index++;
	lst = ft_lstnew_split(str, index, c);
	index += lst->content_size;
	header = lst;
	while (i < ft_nb_mots(str, c))
	{
		while (str[index] == c && str[index])
			index++;
		tmp = ft_lstnew_split(str, index, c);
		index += tmp->content_size;
		lst->next = tmp;
		lst = lst->next;
		i++;
	}
	lst->next = NULL;
	return (header);
}
