/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:59:15 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/07 18:55:30 by seungyki         ###   ########.fr       */
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
	int a;
	int b;

	a = r / 4;
	b = r / 2;
	while (--a)
		list = list->next;
	arr[3] = list->index;
	while (--b)
		list = list->next;
	arr[4] = list->index;
}

void	arr_init(t_list **list, int *arr, int r)
{
	int tmp;
	int move;

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

void	reving(t_list **a, t_list **b, int *arr)
{
	int i;

	i = 0;
	while (arr[0] > i && arr[1] > i)
	{
		reverse_rr(a, b);
		i++;
	}
	if (i == arr[1] && i < arr[0])
		while (arr[0] > i++)
			reverse_a(a);
	if (i == arr[0] && i < arr[1])
		while (arr[1] > i++)
			reverse_b(b);
}