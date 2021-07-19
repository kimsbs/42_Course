#include "ps.h"

void	b_to_a_mini2(t_list **a, t_list **b, int *arr, int r)
{
	if (arr[5])
	{
		rotate_a(a);
		arr[0]++;
		arr[5]--;
	}
	push_a(a, b);
	arr[2]++;
	if ((*a)->index <= arr[4])
	{
		arr[5]++;
		if (r == 0)
		{
			rotate_a(a);
			arr[0]++;
		}
	}
}

void	b_to_a_mini(t_list **a, t_list **b, int *arr, int r)
{
	if ((*b)->index <= arr[3])
		if (arr[5])
		{
			rotate_rr(a, b);
			arr[0]++;
			arr[1]++;
			arr[5]--;
		}
		else
		{
			rotate_b(b);
			arr[1]++;
		}
	else
		b_to_a_mini2(a, b, arr, r);
}

void	b_to_a(t_list **a, t_list **b, int r, int *flag)
{
	int		arr[6];

	*flag = 1;
	if (r <= 3)
	{
		r_is_small(a, b, 0, r);
		return ;	
	}
	arr_init(b, arr, r);
	while (r--)
		b_to_a_mini(a, b, arr, r);
	a_to_b(a, b, arr[2]-arr[0], flag);
	reving(a, b, arr, flag);
	a_to_b(a, b, arr[0], flag);
	b_to_a(a, b, arr[1], flag);
}