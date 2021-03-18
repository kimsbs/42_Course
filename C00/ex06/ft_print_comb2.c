/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:27:06 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/22 13:10:41 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_int(int a, int b, char space)
{
	char	q;
	char	w;

	q = a / 10 + '0';
	w = a % 10 + '0';
	write(1, &q, 1);
	write(1, &w, 1);
	write(1, &space, 1);
	q = b / 10 + '0';
	w = b % 10 + '0';
	write(1, &q, 1);
	write(1, &w, 1);
}

void	ft_print_comb2(void)
{
	char	comma[2];
	int		a;
	int		b;

	a = 0;
	b = 1;
	comma[0] = ',';
	comma[1] = ' ';
	while (a < 99)
	{
		print_int(a, b, comma[1]);
		if (a != 98)
		{
			write(1, comma, 2);
		}
		if (b == 99)
		{
			a++;
			b = a + 1;
		}
		else
		{
			b++;
		}
	}
}
