/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:12:19 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/20 19:13:26 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static	void	short_swap_a(t_list **a, int cases)
{
	if (cases == 1)
	{
		swap_a(a);
		reverse_a(a);
	}	
	else if (cases == 2)
		rotate_a(a);
	else if (cases == 3)
		swap_a(a);
	else if (cases == 4)
		reverse_a(a);
	else if (cases == 5)
	{
		reverse_a(a);
		swap_a(a);
	}
}

void	only_three(t_list **a)
{
	int		arr[3];
	int		cases;
	t_list	*now;

	now = *a;
	arr[0] = now->index;
	arr[1] = now->next->index;
	arr[2] = now->next->next->index;
	cases = divide_case(arr);
	short_swap_a(a, cases);
}
