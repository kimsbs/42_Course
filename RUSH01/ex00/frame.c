/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:24:19 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 13:39:40 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "solve.h"

int		checker(int arr[][11], int size)
{
	int sum;
	int i;

	i = 1;
	while (i <= size)
	{
		sum = arr[0][i] + arr[size + 1][i];
		if (sum > size + 1 || sum <= 2)
			return (1);
		sum = arr[i][0] + arr[i][size + 1];
		if (sum > size + 1 || sum <= 2)
			return (1);
		i++;
	}
	return (0);
}

int		find_size(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			cnt++;
		str++;
	}
	return (cnt);
}

void	make_input(char *str, int *arr)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			arr[cnt++] = *str - '0';
		}
		str++;
	}
}

void	make_metrix(int arr[][11], int *input, int size)
{
	int i;

	makezero(arr);
	i = 0;
	while (++i <= size)
		arr[0][i] = input[i - 1];
	i = 0;
	while (++i <= size)
		arr[size + 1][i] = input[i + size - 1];
	i = 0;
	while (++i <= size)
		arr[i][0] = input[i + size + size - 1];
	i = 0;
	while (++i <= size)
		arr[i][size + 1] = input[i + size + size + size - 1];
}
