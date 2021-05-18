/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:40:47 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/18 16:39:08 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int sol;
	int sol2;

	sol = ft_printf("[%s]", sol);
	printf("\n");
	sol2 = printf("[%s]", NULL);
	printf("\n%d %d\n", sol, sol2);
	system("Leaks a");
}
