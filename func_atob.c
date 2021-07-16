#include "ps.h"

void	a_to_b_mini(t_list **a, t_list **b, int *cnt, int *arr)
{
	if ((*a)->index >= arr[4])
	{
		rotate_a(a, cnt);
		arr[0]++;
	}
	else
	{
		push_b(a, b, cnt);
		arr[2]++;
		if ((*b)->index > arr[3])
		{	
			rotate_b(b, cnt);
			arr[1]++;
		}
	}
}

void	a_to_b(t_list **a, t_list **b, int *cnt, int r)
{
	int		arr[5]; 
	
	//0 - ra_cnt / 1 - rb_cnt / 2 - push / 3 - pivot_min / 4 - pivot_max
	if (r <= 3)
	{
		if (r == 2)
			r_is_small(a, cnt, 1);
		else if (r == 3)
			short_swap(a, b, cnt, 1);
		return ;
	}
	arr_init(a, arr);
	while (--r >= 0)
		a_to_b_mini(a, b, cnt, arr);
	reving(a, b, arr, cnt);
	a_to_b(a, b, cnt, arr[0]);
	b_to_a(a, b, cnt, arr[1]);
	b_to_a(a, b, cnt, arr[2] - arr[1]);
}