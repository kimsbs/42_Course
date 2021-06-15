/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:24:50 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/15 16:50:14 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		move;
	int		data;

	b = NULL;
	if (argc <= 1)
		return (0);
	move = 0;
	while(++move < argc)
	{
		data = ft_atoi(argv[move]);
		add_back(&a, data);
	}
	print_list(a, b);
	for(int i = 0 ; i < 5 ; i++)
		push_b(&a, &b);
	print_list(a, b);
	rotate_rr(&a, &b);
	print_list(a, b);
	reverse_rr(&a, &b);
	print_list(a, b);
	swap_s(&a, &b);
	print_list(a, b);
}
