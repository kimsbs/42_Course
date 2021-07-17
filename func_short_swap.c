#include "ps.h"

int		divide_case(int *arr)
{	
	int		cases;

	cases = 1;
	if(arr[0] > arr[1])
		if(arr[0] > arr[2])
			if(arr[1] > arr[2])
				cases = 1;
			else
				cases = 2;
		else
			cases = 3;
	else
		if(arr[1] > arr[2])
			if(arr[0] > arr[2])
				cases = 4;
			else 
				cases = 5;
		else
			cases = 6;
	return (cases);
}

void	short_swap_a(t_list **a, int cases)
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

void	short_swap_b(t_list **b, int cases)
{
	if (cases == 2)
	{
		reverse_b(b);
		swap_b(b);
	}
	else if(cases == 3)
		reverse_b(b);
	else if(cases == 4)
		swap_b(b);
	else if(cases == 5)
		rotate_b(b);
	else if(cases == 6)
	{
		swap_b(b);
		reverse_b(b);
	}
}

void	short_swap(t_list **a, t_list **b, int flag)
{
	int		arr[3];
	int		cases;
	t_list	*now;

	if(flag)
		now = *a;
	else
		now = *b;
	arr[0] = now->index;
	arr[1] = now->next->index;
	arr[2] = now->next->next->index;
	cases = divide_case(arr);
	if(flag)
		short_swap_a(a, cases);
	else
		short_swap_b(b, cases);
}

void	r_is_small(t_list **a, t_list **b, int flag, int r)
{
	if(r == 2)
	{
		if(flag && (*a)->index > (*a)->next->index)
			swap_a(a);
		else if(!flag && (*b)->index < (*b)->next->index)
			swap_b(b);
	}
	else if(r == 3)
		short_swap(a, b, flag);
}