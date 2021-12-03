/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:27:08 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/18 03:28:23 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_sol(int tmp)
{
	if (tmp == 0)
		write(1, "0", 1);
	else if (tmp < 0)
	{
		write(1, "-", 1);
		ft_itoa(tmp);
	}
	else
		ft_itoa(tmp);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (!str_cmp(argv[2], "+"))
		ft_add(a, b, 0);
	else if (!str_cmp(argv[2], "-"))
		ft_minus(a, b, 0);
	else if (!str_cmp(argv[2], "*"))
		ft_product(a, b, 0);
	else if (!str_cmp(argv[2], "/"))
		ft_div(a, b);
	else if (!str_cmp(argv[2], "%"))
		ft_mod(a, b);
	else
	{
		write(1, "0\n", 2);
		return (0);
	}
}
