/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:38:12 by ydumaine          #+#    #+#             */
/*   Updated: 2022/01/29 13:33:19 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_pair_or_impair(char *str, int i)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == '-')
			d++;
		i++;
	}
	if (d % 2 == 0)
		c = 1;
	return (c);
}

int	ft_atoi(char *str)
{
	int	i;
	int	a;
	int	c;
	int	b;

	b = 0;
	a = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			i++;
	c = ft_pair_or_impair(str, i);
	while (str[i] == 43 || str[i] == 45 || str[i] == 48)
		i++;
	if (str [i] >= 48 && str[i] <= 57)
		a = i;
	while (str [i] >= 48 && str[i] <= 57)
	{
		b = b * 10 - (str[i] - 48);
		i++;
	}
	if (c == 1)
		b = -b;
	return (b);
}
