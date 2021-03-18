/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnum2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:54:05 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 21:40:19 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "findnum.h"
#include "solve.h"

int		rowpossible(int arr[][11], int q, int data, int size)
{
	int i;

	i = 0;
	while (++i <= size)
	{
		if (arr[i][q] == data)
			return (0);
	}
	return (1);
}

int		colpossible(int arr[][11], int p, int data, int size)
{
	int i;

	i = 0;
	while (++i <= size)
	{
		if (arr[p][i] == data)
			return (0);
	}
	return (1);
}

void	inputmetrix(int arr[][11], int i, int j, int size)
{
	int data;

	data = 0;
	while (++data <= size)
	{
		if (colpossible(arr, i, data, size))
			if (rowpossible(arr, j, data, size))
			{
				arr[i][j] = data;
				moving(arr, size);
				arr[i][j] = 0;
			}
	}
}

int		row_count(int arr[][11], int size)
{
	int tmp[11];
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	while (++i <= size)
	{
		j = -1;
		while (++j <= size + 1)
			tmp[j] = arr[i][j];
		count += checking(tmp, size);
		rev_tmp(tmp, size + 2);
		count += checking(tmp, size);
	}
	return (count);
}

int		col_count(int arr[][11], int size)
{
	int tmp[11];
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	while (++i <= size)
	{
		j = -1;
		while (++j <= size + 1)
			tmp[j] = arr[j][i];
		count += checking(tmp, size);
		rev_tmp(tmp, size + 2);
		count += checking(tmp, size);
	}
	return (count);
}
