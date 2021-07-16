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

void	arr_init(t_list **a, int *arr)
{
	int tmp;
	int move;

	move = -1;
	while(++move < 3)
		arr[move] = 0;
	arr[3] = (*a)->index;
	arr[4] = (*a)->prev->index;
	if(arr[3] > arr[4])
	{
		tmp = arr[3];
		arr[3] = arr[4];
		arr[4] = tmp;
	}
}

int		reving(t_list **a, t_list **b, int *arr)
{
	int tmp;
	int tmp2;
	int cnt;

	cnt = 0;
	tmp = 0;
	while(arr[0] > tmp && arr[1] > tmp)
	{
		reverse_rr(a, b, &cnt);
		tmp++;
	}
	tmp2 = tmp;
	while(arr[0] > tmp)
	{
		reverse_a(a, &cnt);
		tmp++;
	}
	while(arr[1] > tmp2)
	{
		reverse_b(b, &cnt);
		tmp2++;
	}
	return (cnt);
}

void	r_is_small(t_list **list, int *cnt, int r, int flag)
{
	if(r <= 1)
		return ;
	if(flag && (*list)->index > (*list)->next->index)
		swap_a(list, cnt);
	else if(!flag && (*list)->index < (*list)->next->index)
		swap_b(list, cnt);
}

void	a_to_b_mini(t_list **a, t_list **b, int *cnt, int *arr)
{
	if((*a)->index >= arr[4])
	{
		rotate_a(a, cnt);
		arr[0]++;
	}
	else
	{
		push_b(a, b, cnt);
		arr[2]++;
		if((*b)->index < arr[3])
		{
			rotate_b(b, cnt);
			arr[1]++;
		}
	}
}

void	a_to_b(t_list **a, t_list **b, int *cnt, int r)
{
	int		arr[5];
	t_list	*last;
	
	//0 - ra_cnt / 1 - rb_cnt / 2 - push / 3 - pivot_min / 4 - pivot_max
	if(*a == NULL)
		return ;
	if(r < 3)
	{
		r_is_small(a, cnt, r, 1);
		return ;
	}
	last = (*a)->prev;
	arr_init(a, arr);
	while(*a != last)
		a_to_b_mini(a, b, cnt, arr);
	a_to_b_mini(a, b, cnt, arr);
	*cnt += reving(a, b, arr);
	a_to_b(a, b, cnt, arr[0]);
	b_to_a(a, b, cnt, arr[1]);
	b_to_a(a, b, cnt, arr[2] - arr[1]);
}

void	b_to_a_mini(t_list **a, t_list **b, int *cnt, int *arr)
{
	if((*b)->index < arr[3])
	{
		rotate_b(b, cnt);
		arr[1]++;
	}
	else
	{
		push_a(a, b, cnt);
		arr[2]++;
		if(*b && (*b)->index < arr[4])
		{
			rotate_a(a, cnt);
			arr[0]++;
		}
	}
}

void	b_to_a(t_list **a, t_list **b, int *cnt, int r)
{
	int		arr[5];
	t_list	*last;

	if(*b == NULL)
		return ;
	if(r < 3)
	{
		r_is_small(b, cnt, r, 0);
		while(--r >= 0)
			push_a(a, b, cnt);
		return ;
	}
	last = (*b)->prev;
	arr_init(b, arr);
	while(*b != last)
		b_to_a_mini(a, b, cnt, arr);
	b_to_a_mini(a, b, cnt, arr);
	a_to_b(a, b, cnt, arr[2]-arr[0]);
	*cnt += reving(a, b, arr);
	a_to_b(a, b, cnt, arr[0]);
	b_to_a(a, b, cnt, arr[1]);
}
