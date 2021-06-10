/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:24:50 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:19:51 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		main(int argc, char **argv)
{
	t_list	*a;
	int		move;
	int		data;

	if (argc <= 1)
		return (0);
	move = 0;
	while(++move < argc)
	{
		data = argv[move][0] - '0';
		add_front(&a, data);
	}
	print_list(a);
	rotate(&a);
	print_list(a);
	reverse_rotate(&a);
	print_list(a);
	swap_element(&a);
	print_list(a);
	rm_front(&a);
	print_list(a);
}
