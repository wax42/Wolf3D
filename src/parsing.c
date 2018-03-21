/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:44:10 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/20 16:46:14 by wsabates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_secur_open(char *str)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		i;

	i = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_exit(0);
	buf[read(fd, buf, BUFF_SIZE)] = '\0';
	if (buf[0] == '\0')
		ft_exit(0);
	while (buf[i])
	{
		if (!ft_isdigit(buf[i]) && buf[i] != '\n' && buf[i] != ' ')
			ft_exit(0);
		i++;
	}
	close(fd);
}

int		**parse_tab(int **tab, int y_max, int x_max, int fd)
{
	int		x;
	int		y;
	int		i;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		x = -1;
		while (line[++i])
		{
			(++x > x_max) ? ft_exit(0) : NULL;
			tab[y][x] = ft_atoi(line + i);
			(tab[y][x] < 0 || tab[y][x] > 9) ? ft_exit(1) : NULL;
			i++;
		}
		ft_strdel(&line);
		y++;
	}
	(y != y_max) ? ft_exit(0) : NULL;
	ft_strdel(&line);
	return (tab);
}

int		**parsing(t_parsing *p, char *str)
{
	int		fd;
	char	*line;
	int		**tab;
	int		y_max;
	int		x_max;

	ft_secur_open(str);
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_exit(0);
	if (get_next_line(fd, &line) == -1)
		ft_exit(0);
	x_max = ft_atoi(line);
	y_max = ft_atoi(line + ft_nbrlen(x_max) + 1);
	tab = ft_tabint(y_max + 1, x_max + 1, 2);
	ft_strdel(&line);
	tab = parse_tab(tab, y_max, x_max, fd);
	p->max.y = y_max;
	p->max.x = x_max;
	(x_max != y_max) ? ft_exit(0) : NULL;
	return (tab);
}
