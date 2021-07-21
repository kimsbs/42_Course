/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_short_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:00:24 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/20 19:05:52 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	divide_case2(int *arr)
{
	int	cases;

	cases = 4;
	if (arr[1] > arr[2])
	{
		if (arr[0] > arr[2])
			cases = 4;
		else
			cases = 5;
	}
	else
		cases = 6;
	return (cases);
}

int	divide_case(int *arr)
{	
	int	cases;

	cases = 1;
	if (arr[0] > arr[1])
	{
		if (arr[0] > arr[2])
		{
			if (arr[1] > arr[2])
				cases = 1;
			else
				cases = 2;
		}
		else
			cases = 3;
	}
	else
		cases = divide_case2(arr);
	return (cases);
}

void	r_is_small(t_list **a, t_list **b, int flag, int r)
{
	if (r == 1 && !flag)
		push_a(a, b);
	else if (r == 2)
	{
		if (flag && (*a)->index > (*a)->next->index)
			swap_a(a);
		else if (!flag && (*b)->index < (*b)->next->index)
			swap_b(b);
		if (!flag)
		{
			push_a(a, b);
			push_a(a, b);
		}
	}
	else if (r == 3)
		short_swap(a, b, flag);
}
