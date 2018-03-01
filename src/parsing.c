/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:44:10 by vguerand          #+#    #+#             */
/*   Updated: 2018/03/01 01:03:24 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void ft_exit(int code)
{
	if (code  == 0)
		ft_putendl("ERROR PARSING");
	if (code  == 1)
		ft_putendl("chiffre trop big");
	if (code  == 0)
		ft_putendl("BUS ERROR");
	exit(0);
}

void		ft_secur_open(char *str)
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

int 	**parsing(char *str)
{
	int fd;
	char *line;
	int **tab;
	int y_max;
	int x_max;
	int y;
	int x;
	int i;

	ft_secur_open(str);
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_exit(0);
	if (get_next_line(fd, &line) == -1)
		ft_exit(0);
	x_max = ft_atoi(line);
	i = ft_nbrlen(x_max) + 1;
	y_max = ft_atoi(line + i);
	tab = ft_tabint(y_max, x_max, '0');
	y = 0;
	while (get_next_line(fd, &line) > 0 && y_max > y)
	{
		i = 0;
		x = 0;
		while (line[i])
		{
			if (ft_isdigit(line[i]))
			{
				if (x > x_max)
					ft_exit(1);
				tab[y][x] = ft_atoi(line + i);
				if (tab[y][x] < 0 || tab[y][x] > 9)
					ft_exit(1);
				x++;
				i++;
			}
			i++;
		}
		ft_strdel(&line);
		y++;
	}
	return (tab);
}
