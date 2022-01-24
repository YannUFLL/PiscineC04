/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:11:07 by ydumaine          #+#    #+#             */
/*   Updated: 2022/01/24 15:05:53 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	x;

	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i])
	{
		x = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[x])
		{
			if (base[x] == base[i])
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	ft_adres(int i, int nbr, int *temp)
{
	int	u;

	u = 0;
	while (nbr > 0 || nbr < 0)
	{
		if (nbr > 0)
			temp[u] = nbr % i;
		if (nbr < 0)
			temp[u] = - (nbr % i);
		nbr = nbr / i;
		u++;
	}
	return (u);
}

void	ft_putnb_base(int nbr, char *base)
{
	int	i;
	int	temp[100];
	int	u;

	i = 0;
	if (ft_check_base(base))
	{
		if (nbr == 0)
			ft_putchar(base[0]);
		else
		{
			while (base[i])
				i++;
			if (nbr < 0)
			{
				ft_putchar('-');
				i = -i;
			}
			u = ft_adres(i, nbr, temp);
			while (--u >= 0)
				ft_putchar(base[temp[u]]);
		}
	}
}
