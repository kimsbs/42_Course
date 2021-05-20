/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:40:47 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/20 11:47:31 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int sol;
	int sol2;

	sol = ft_printf("[%10d]", -1);
	printf("\n");
	sol2 = printf("[%10d]", -1);
	printf("\n%d %d\n", sol, sol2);
	system("Leaks a");
}
