#include "ps.h"

void	a_to_b_mini2(t_list **a, t_list **b, int *arr, int r)
{
	if (arr[5])
	{	
		rotate_b(b);
		arr[1]++;
		arr[5]--;
	}
	push_b(a, b);
	arr[2]++;
	if ((*b)->index >= arr[3])
	{	
		arr[5]++;
		if (r == 0)
		{
			rotate_b(b);
			arr[1]++;
		}
	}
}

void	a_to_b_mini(t_list **a, t_list **b, int *arr, int r)
{
	if ((*a)->index >= arr[4])
		if(arr[5])
		{
			rotate_rr(a, b);
			arr[1]++;
			arr[0]++;
			arr[5]--;
		}
		else
		{
			rotate_a(a);
			arr[0]++;
		}
	else
		a_to_b_mini2(a, b, arr, r);
}

void	a_to_b(t_list **a, t_list **b, int r, int *flag)
{
	int		arr[6];

	if (r <= 3)
	{
		r_is_small(a, b, 1, r);
		return ;
	}
	arr_init(a, arr, r);
	while (r--)
		a_to_b_mini(a, b, arr, r);
	reving(a, b, arr, flag);
	a_to_b(a, b, arr[0], flag);
	b_to_a(a, b, arr[1], flag);
	b_to_a(a, b, arr[2] - arr[1], flag);
}
