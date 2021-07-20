/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:24:50 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/20 19:16:47 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	is_dup(t_list **a, int argc)
{
	int		data;
	t_list	*pre;
	t_list	*now;

	if (argc == 1)
		return (1);
	pre = *a;
	while (pre->next != *a)
	{
		data = pre->index;
		now = pre->next;
		while (now->next != *a)
		{
			if (now->index == data)
				return (0);
			now = now->next;
		}
		if (now->index == data)
			return (0);
		pre = pre->next;
	}
	if (pre->index == (*a)->index)
		return (0);
	return (1);
}

void	sorting(t_list **a, t_list **b, int argc)
{
	int	tmp;

	tmp = 0;
	if (!is_dup(a, argc))
		write(1, "Error\n", 6);
	else if (!is_sorted(a))
	{
		if (argc == 3)
			only_three(a);
		else if (argc == 5)
			sort_five(a, b);
		else
			a_to_b(a, b, argc, &tmp);
	}
	free_list(a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		move;
	long	data;

	if (argc <= 1)
		return (0);
	a = NULL;
	b = NULL;
	move = 0;
	while (++move < argc)
	{
		data = ft_atoi(argv[move]);
		if (data > 2147483647 || data < -2147483648)
		{
			write(1, "Error\n", 7);
			exit(-1);
		}
		add_back(&a, data);
	}
	sorting(&a, &b, argc - 1);
}
