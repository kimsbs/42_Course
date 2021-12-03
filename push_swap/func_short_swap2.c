/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_short_swap2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:06:38 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/20 19:09:27 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static	void	short_swap_a2(t_list **a, int cases)
{
	if (cases == 4)
	{
		rotate_a(a);
		swap_a(a);
		reverse_a(a);
		swap_a(a);
	}
	else if (cases == 5)
	{
		rotate_a(a);
		swap_a(a);
		reverse_a(a);
	}
}

static	void	short_swap_a(t_list **a, int cases)
{
	if (cases == 1)
	{
		swap_a(a);
		rotate_a(a);
		swap_a(a);
		reverse_a(a);
		swap_a(a);
	}	
	else if (cases == 2)
	{
		swap_a(a);
		rotate_a(a);
		swap_a(a);
		reverse_a(a);
	}
	else if (cases == 3)
		swap_a(a);
	else
		short_swap_a2(a, cases);
}

static	void	short_swap_b2(t_list **a, t_list **b, int cases)
{
	if (cases == 5)
	{
		swap_b(b);
		push_a(a, b);
		swap_b(b);
		push_a(a, b);
		push_a(a, b);
	}
	else if (cases == 6)
	{
		swap_b(b);
		push_a(a, b);
		swap_b(b);
		push_a(a, b);
		swap_a(a);
		push_a(a, b);
	}
	else if (cases == 1)
	{
		push_a(a, b);
		push_a(a, b);
		push_a(a, b);
	}
}

static	void	short_swap_b(t_list **a, t_list **b, int cases)
{
	if (cases == 2)
	{
		push_a(a, b);
		swap_b(b);
		push_a(a, b);
		push_a(a, b);
	}
	else if (cases == 3)
	{
		push_a(a, b);
		swap_b(b);
		push_a(a, b);
		swap_a(a);
		push_a(a, b);
	}
	else if (cases == 4)
	{
		swap_b(b);
		push_a(a, b);
		push_a(a, b);
		push_a(a, b);
	}
	else
		short_swap_b2(a, b, cases);
}

void	short_swap(t_list **a, t_list **b, int flag)
{
	int		arr[3];
	int		cases;
	t_list	*now;

	if (flag)
		now = *a;
	else
		now = *b;
	arr[0] = now->index;
	arr[1] = now->next->index;
	arr[2] = now->next->next->index;
	cases = divide_case(arr);
	if (flag)
		short_swap_a(a, cases);
	else
		short_swap_b(a, b, cases);
}
