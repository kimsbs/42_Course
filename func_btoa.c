#include "ps.h"

void	b_to_a_mini(t_list **a, t_list **b, int *cnt, int *arr)
{
	if ((*b)->index <= arr[3])
	{
		rotate_b(b, cnt);
		arr[1]++;
	}
	else
	{
		push_a(a, b, cnt);
		arr[2]++;
		if (*b && (*b)->index <= arr[4])
		{
			rotate_a(a, cnt);
			arr[0]++;
		}
	}
}

void	b_to_a(t_list **a, t_list **b, int *cnt, int r)
{
	int		arr[5];

	if (r <= 3)
	{
		if (r == 2)
			r_is_small(b, cnt, 0);
		else if (r == 3)
			short_swap(a, b, cnt, 0);
		while (--r >= 0)
			push_a(a, b, cnt);
		return ;
	}
	arr_init(b, arr);
	while (--r >= 0)
		b_to_a_mini(a, b, cnt, arr);
	a_to_b(a, b, cnt, arr[2]-arr[0]);
	reving(a, b, arr, cnt);
	a_to_b(a, b, cnt, arr[0]);
	b_to_a(a, b, cnt, arr[1]);
}