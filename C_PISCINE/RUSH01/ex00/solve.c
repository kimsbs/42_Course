/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:24:50 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 21:41:55 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "findnum2.h"
#include <stdio.h>

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	rev_tmp(int *tmp, int size)
{
	int i;
	int last;

	last = size - 1;
	i = 0;
	while (i < size / 2)
	{
		swap(&tmp[i], &tmp[last - i]);
		i++;
	}
}

int		checking(int *tmp, int size)
{
	int j;
	int max;
	int cnt;

	cnt = 1;
	j = 1;
	max = tmp[1];
	while (++j <= size)
	{
		if (max < tmp[j])
		{
			max = tmp[j];
			cnt++;
		}
	}
	if (cnt == tmp[0])
		return (1);
	else
		return (0);
}

int		check_main(int arr[][11], int size)
{
	int count;

	count = 0;
	count += row_count(arr, size);
	count += col_count(arr, size);
	if (count == size * 4)
		return (1);
	else
		return (0);
}

void	makezero(int arr[][11])
{
	int i;
	int j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}
