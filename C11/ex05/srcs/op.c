/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:08:20 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/18 00:24:24 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	ft_add(int a, int b, int sol)
{
	sol = a + b;
	print_sol(sol);
}

void	ft_minus(int a, int b, int sol)
{
	sol = a - b;
	print_sol(sol);
}

void	ft_div(int a, int b)
{
	char *str;

	str = "Stop : division by zero\n";
	if (b == 0)
		write(2, str, str_len(str));
	else
		print_sol(a / b);
}

void	ft_mod(int a, int b)
{
	char *str;

	str = "Stop : modulo by zero\n";
	if (b == 0)
		write(2, str, str_len(str));
	else
		print_sol(a % b);
}

void	ft_product(int a, int b, int sol)
{
	sol = a * b;
	print_sol(sol);
}
