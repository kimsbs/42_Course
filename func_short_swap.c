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

void	short_swap_a(t_list **a, int *cnt, int cases)
{
	if (cases == 1)
	{
		swap_a(a, cnt);
		reverse_a(a, cnt);
	}	
	else if (cases == 2)
		rotate_a(a, cnt);
	else if (cases == 3)
		swap_a(a, cnt);
	else if (cases == 4)
		reverse_a(a, cnt);
	else if (cases == 5)
	{
		reverse_a(a, cnt);
		swap_a(a, cnt);
	}
}

void	short_swap_b(t_list **b, int *cnt, int cases)
{
	if (cases == 2)
	{
		reverse_b(b, cnt);
		swap_b(b, cnt);
	}
	else if(cases == 3)
		reverse_b(b, cnt);
	else if(cases == 4)
		swap_b(b, cnt);
	else if(cases == 5)
		rotate_b(b, cnt);
	else if(cases == 6)
	{
		swap_b(b, cnt);
		reverse_b(b, cnt);
	}
}

void	short_swap(t_list **a, t_list **b, int *cnt, int flag)
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
		short_swap_a(a, cnt, cases);
	else
		short_swap_b(b, cnt, cases);
}

void	r_is_small(t_list **list, int *cnt, int flag)
{
	if(flag && (*list)->index > (*list)->next->index)
		swap_a(list, cnt);
	else if(!flag && (*list)->index < (*list)->next->index)
		swap_b(list, cnt);
}