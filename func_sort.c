/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:59:15 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/20 19:11:23 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	is_sorted(t_list **header)
{
	t_list	*move;
	int		now;
	int		next;

	move = *header;
	while (move->next != *header)
	{
		now = move->index;
		next = move->next->index;
		if (now > next)
			return (0);
		move = move->next;
	}
	return (1);
}

void	pivot_alloc(t_list *list, int *arr, int r)
{
	int	*tmp;
	int	move;

	tmp = (int *)malloc(sizeof(int) * r);
	move = 0;
	while (move < r)
	{
		tmp[move++] = list->index;
		list = list->next;
	}
	bubble(tmp, r);
	arr[3] = tmp[r / 3];
	arr[4] = tmp[r * 2 / 3];
	free(tmp);
}

void	arr_init(t_list **list, int *arr, int r)
{
	int	tmp;
	int	move;

	move = -1;
	while (++move < 6)
		arr[move] = 0;
	pivot_alloc(*list, arr, r);
	if (arr[3] > arr[4])
	{
		tmp = arr[3];
		arr[3] = arr[4];
		arr[4] = tmp;
	}
}

void	reving(t_list **a, t_list **b, int *arr, int *flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*flag = 1;
	if (*flag)
	{
		while (arr[0] > i && arr[1] > j)
		{
			reverse_rr(a, b);
			i++;
			j++;
		}
		while (arr[0] > i++)
			reverse_a(a);
	}
	while (arr[1] > j++)
		reverse_b(b);
}
