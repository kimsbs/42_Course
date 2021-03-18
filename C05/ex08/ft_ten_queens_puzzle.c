/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:45:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/10 21:51:54 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int g_cnt = 0;

void	print(int *arr)
{
	int		i;
	int		c;

	i = -1;
	while (++i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	g_cnt++;
}

int		possible(int *arr, int pivot)
{
	int i;

	i = -1;
	while (++i < pivot)
		if (arr[i] == arr[pivot])
			return (0);
	i = -1;
	while (++i < pivot)
	{
		if (arr[i] - arr[pivot] == i - pivot
				|| arr[i] - arr[pivot] == pivot - i)
			return (0);
		if (arr[pivot] - arr[i] == pivot - i
				|| arr[pivot] - arr[i] == i - pivot)
			return (0);
	}
	return (1);
}

void	solve(int *arr, int pivot)
{
	int i;

	if (pivot == 10)
		print(arr);
	else
	{
		i = -1;
		while (++i < 10)
		{
			arr[pivot] = i;
			if (possible(arr, pivot))
				solve(arr, pivot + 1);
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		arr[10];
	int		i;

	i = -1;
	while (++i < 10)
		arr[i] = -1;
	solve(arr, 0);
	return (g_cnt);
}
