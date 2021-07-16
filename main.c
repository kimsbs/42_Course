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

void	sorting(t_list **a, t_list **b)
{
	int cnt;

	cnt = 0;
	if(!is_sorted(a))
		a_to_b(a, b, &cnt, 3);
	print_list(*a, *b);
	free_list(a, b);
	printf("%d\n", cnt);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		move;
	int		data;

	if (argc <= 1)
		return (0);
	a = NULL;
	b = NULL;
	move = 0;
	while (++move < argc)
	{
		data = ft_atoi(argv[move]);
		add_back(&a, data);
	}
	sorting(&a, &b);
}
