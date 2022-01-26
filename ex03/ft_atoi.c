/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:38:12 by ydumaine          #+#    #+#             */
/*   Updated: 2022/01/26 14:40:12 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_power(int a, int j)
{
	j--;
	if (j <= 0)
		return (1);
	else
		a = ft_power(a, j) * 10;
	return (a);
}

int	ft_converter(char *str, int a, int i)
{
	int	b;

	b = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		b = b + (str[i] - 48) * -a;
		a = a / 10;
		i++;
	}
	return (b);
}

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
	int	j;
	int	a;
	int	c;
	int	b;

	j = 0;
	i = 0;
	a = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			i++;
	c = ft_pair_or_impair(str, i);
	while (str[i] == 43 || str[i] == 45)
		i++;
	if (str [i] >= 48 && str[i] <= 57)
		a = i;
	while (str [i] >= 48 && str[i] <= 57)
	{
		i++;
		j++;
	}
	b = ft_converter(str, ft_power(-1, j), a);
	if (c == 1 && b < 0)
		b = -b ;
	return (b);
}
