/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:38:03 by vguerand          #+#    #+#             */
/*   Updated: 2017/11/14 17:39:13 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_pass(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == 32 || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	unsigned int	nb;
	int				neg;
	int				i;

	neg = 0;
	nb = 0;
	i = ft_pass(str);
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (neg == 1)
	{
		nb = -nb;
	}
	return (nb);
}
