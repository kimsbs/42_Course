/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:25:28 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/17 14:34:57 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		min_num(int a, int b, int c)
{
	int min;

	if (a > b)
		min = b;
	else
		min = a;
	if (min > c)
		min = c;
	return (min);
}

void	print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	print_all(int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		print_str(g_matrix[i].data);
		i++;
	}
}

void	fill(void)
{
	int x;
	int y;
	int tmp;

	x = g_x - g_max;
	y = g_y - g_max;
	tmp = g_y;
	while (x < g_x)
	{
		g_y = tmp;
		while (y < g_y)
		{
			g_matrix[g_x].data[g_y] = g_find[2];
			g_y--;
		}
		g_x--;
	}
}
