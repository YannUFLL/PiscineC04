/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:50:55 by ydumaine          #+#    #+#             */
/*   Updated: 2022/01/24 17:23:00 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_affi(int i, int nbr)
{
	char	a[20];
	int		u;

	u = 0;
	while (nbr > 0 || nbr < 0)
	{
		if (nbr > 0)
			a[u] = nbr % i;
		if (nbr < 0)
			a[u] = - (nbr % i);
		nbr = nbr / i;
		u++;
	}
	while (--u >= 0)
		ft_putchar(a[u] + 48);
}

void	ft_putnbr(int nbr)
{
	int	i;

	i = 10;
	if (nbr < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	ft_affi(i, nbr);
}
