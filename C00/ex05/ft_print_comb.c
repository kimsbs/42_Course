/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:02:01 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/21 14:52:35 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int a, int b, int c)
{
	char dummy[3];

	dummy[0] = a + '0';
	dummy[1] = b + '0';
	dummy[2] = c + '0';
	write(1, dummy, sizeof(dummy));
}

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;
	char	comma[2];

	comma[0] = ',';
	comma[1] = ' ';
	a = -1;
	while (++a < 10)
	{
		b = a;
		while (++b < 10)
		{
			c = b;
			while (++c < 10)
			{
				print_num(a, b, c);
				if (a != 7)
				{
					write(1, comma, 2);
				}
			}
		}
	}
}
