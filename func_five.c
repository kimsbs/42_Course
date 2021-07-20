/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:44:13 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/20 18:57:00 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	bubble(int *arr, int r)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	while (++i < r)
	{
		j = i;
		while (++j < r)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

static	void	move_btoa(t_list **a, t_list **b, int flag)
{
	if (!flag)
	{
		push_a(a, b);
		push_a(a, b);
		rotate_a(a);
		rotate_a(a);
	}
	else
	{
		push_a(a, b);
		rotate_a(a);
		push_a(a, b);
		rotate_a(a);
	}
}

static	void	sorting(t_list **a, t_list **b, int num1, int num2)
{
	int	cnt;
	int	flag;

	flag = 0;
	cnt = 0;
	while (cnt != 2)
	{
		if ((*a)->index == num1 || (*a)->index == num2)
		{
			push_b(a, b);
			cnt++;
		}
		else
			rotate_a(a);
	}
	only_three(a);
	if ((*b)->index < (*b)->next->index)
		flag = 1;
	move_btoa(a, b, flag);
}

void	sort_five(t_list **a, t_list**b)
{
	int		arr[5];
	int		move;
	t_list	*list;

	move = -1;
	list = *a;
	while (++move < 5)
	{
		arr[move] = list->index;
		list = list->next;
	}
	bubble(arr, 5);
	sorting(a, b, arr[0], arr[1]);
}
