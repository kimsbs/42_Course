#include "ps.h"

int		divide_case(int *arr)
{	
	int		cases;

	cases = 1;
	if (arr[0] > arr[1])
		if (arr[0] > arr[2])
			if (arr[1] > arr[2])
				cases = 1;
			else
				cases = 2;
		else
			cases = 3;
	else
		if (arr[1] > arr[2])
			if (arr[0] > arr[2])
				cases = 4;
			else 
				cases = 5;
		else
			cases = 6;
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
		if(!flag)
		{
			push_a(a, b);
			push_a(a, b);
		}
	}
	else if (r == 3)
		short_swap(a, b, flag);
}