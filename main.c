/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:24:50 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/07 19:00:11 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sorting(t_list **a, t_list **b, int argc)
{
	if (!is_sorted(a))
	{
		if (argc == 3)
			only_three(a);
		else if(argc == 5)
			sort_five(a, b);
		else
			a_to_b(a, b, argc);
	}
	//print_list(*a, *b);
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
