/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:40:47 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/18 15:26:50 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *s2 = "my name is";
	char *s1 = "hello World!";
	char c = 'a';
	int sol;
	int sol2;

	sol = ft_printf("[%-*s %s %c %-.*d]", 15, s1, s2, c, 5, 10);
	printf("\n");
	sol2 = printf("[%-*s %s %c %-.*d]", 15, s1 ,s2, c, 5, 10);
	printf("\n%d %d\n", sol, sol2);
	system("Leaks a");
}
