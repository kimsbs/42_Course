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

int		list_data(t_list *a, int r)
{
	while(--r)
		a = a->next;
	return (a->index);
}

void	arr_init(t_list **a, int *arr, int r)
{
	int tmp;
	int move;

	move = -1;
	while (++move < 3)
		arr[move] = 0;
	arr[3] = (*a)->next->index;
	arr[4] = list_data((*a)->prev, r);
	if (arr[3] > arr[4])
	{
		tmp = arr[3];
		arr[3] = arr[4];
		arr[4] = tmp;
	}
}

void	reving(t_list **a, t_list **b, int *arr, int *cnt)
{
	int tmp;
	int tmp2;

	tmp = arr[0];
	tmp2 = arr[1];
	while (tmp > 0 && tmp2 > 0)
	{
		reverse_rr(a, b, cnt);
		tmp--;
		tmp2--;
	}
	while (--tmp >= 0)
		reverse_a(a, cnt);
	while (--tmp2 >= 0)
		reverse_b(b, cnt);
}