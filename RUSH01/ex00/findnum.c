/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:23:54 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/10 20:48:43 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "solve.h"
#include "findnum2.h"

extern int g_flag;

void	print(int arr[][11], int size)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < size + 1)
	{
		j = 1;
		while (j < size + 1)
		{
			c = arr[i][j] + '0';
			write(1, " ", 1);
			write(1, &c, 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int		moving(int arr[][11], int size)
{
	int i;
	int j;

	if (g_flag == 1)
		return (0);
	i = 0;
	while (++i <= size)
	{
		j = 0;
		while (++j <= size)
			if (arr[i][j] == 0)
			{
				inputmetrix(arr, i, j, size);
				return (0);
			}
	}
	if (check_main(arr, size) && g_flag == 0)
	{
		g_flag++;
		print(arr, size);
	}
	return (0);
}
