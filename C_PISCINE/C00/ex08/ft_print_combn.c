/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:27:52 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/22 14:31:21 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *arr, int n)
{
	int i;

	i = 0;
	arr[i] = '0';
	while (++i < n)
	{
		arr[i] = arr[i - 1] + 1;
	}
	write(1, arr, n);
}

void	adder(char *arr, int size, int p)
{
	int max;

	max = 10 - size + p;
	if (arr[p] != max + '0')
	{
		arr[p] += 1;
	}
	else
	{
		if (p != 0)
		{
			adder(arr, size, p - 1);
			arr[p] = arr[p - 1] + 1;
		}
	}
}

void	ft_print_combn(int n)
{
	char	comma[2];
	char	arr[10];
	int		max;

	max = 10 - n;
	comma[0] = ',';
	comma[1] = ' ';
	init(arr, n);
	while (arr[0] < max + '0' && arr[0] >= '0')
	{
		adder(arr, n, n - 1);
		write(1, comma, 2);
		write(1, arr, n);
	}
}
