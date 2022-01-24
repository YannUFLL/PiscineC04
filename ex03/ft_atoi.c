/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:38:12 by ydumaine          #+#    #+#             */
/*   Updated: 2022/01/24 15:06:45 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_power(int a, int j)
{
	j--;
	if (j <= 0)
		return (1);
	else
		a = ft_power(a, j) * 10;
	return (a);
}

int	ft_pair(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			c++;
		i++;
	}
	i = 0;
	if (c % 2 == 0)
		c = 1;
	else
		c = 0;
	return (c);
}

int	ft_counting(char *str, int *h)
{
	int	i;
	int	j;
	int	a;

	j = 0;
	i = 0;
	a = -1;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			a = i;
		while (str [i + j] >= 48 && str[i + j] <= 57)
			j++;
		if (a > -1)
			break ;
		i++;
	}
	*h = j;
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

int	ft_atoi(char *str)
{
	int	a;
	int	b;
	int	i;
	int	j;
	int	*h;

	h = &j;
	a = -1;
	b = 0;
	j = 0;
	ft_counting(str, h);
	b = ft_converter(str, ft_power(a, j), ft_counting(str, h););
	if (ft_pair(str) == 1)
		b = -b;
	return (b);
}
