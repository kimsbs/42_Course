/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:58:38 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 18:29:07 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		checker(char *base)
{
	int cnt;
	int pivot;

	cnt = 0;
	while (base[cnt])
	{
		if (base[cnt] == '+' || base[cnt] == '-')
			return (0);
		pivot = 0;
		while (pivot < cnt)
		{
			if (base[pivot] == base[cnt])
				return (0);
			pivot++;
		}
		cnt++;
	}
	if (cnt <= 1)
		return (0);
	return (1);
}

void	change(int nbr, int size, char *base)
{
	char m;

	m = '-';
	if (nbr == -2147483648)
	{
		change(nbr / size, size, base);
		nbr %= size;
		nbr *= -1;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, &m, 1);
	}
	if (nbr >= size)
	{
		change(nbr / size, size, base);
	}
	nbr %= size;
	write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;
	int check;

	len = 0;
	while (base[len])
		len++;
	check = checker(base);
	if (check != 0)
	{
		change(nbr, len, base);
	}
}
