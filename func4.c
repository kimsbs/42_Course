/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:41:54 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/04 17:47:11 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static	int		find_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	input_data(long n, char *sol, int size, int start)
{
	int		tmp;

	while (size >= start)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp *= -1;
		n /= 10;
		sol[size] = tmp + '0';
		size--;
	}
}

char			*ft_itoa(int n)
{
	char	*sol;
	int		size;
	int		start;

	size = find_size(n);
	if (n < 0)
		size++;
	if (!(sol = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
	{
		start = 1;
		sol[0] = '-';
	}
	else
		start = 0;
	input_data(n, sol, size - 1, start);
	sol[size] = '\0';
	return (sol);
}

char			*make_str(unsigned int c)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}
