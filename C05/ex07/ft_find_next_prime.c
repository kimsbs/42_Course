/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:09:53 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/08 14:52:09 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_prime(int nb)
{
	unsigned int move;
	unsigned int tmp;

	tmp = (unsigned int)nb;
	move = 2;
	while (move * move <= tmp)
	{
		if (tmp % move == 0)
			return (0);
		move++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int check;

	if (nb <= 2)
		return (2);
	check = 0;
	while (!check)
	{
		check = is_prime(nb);
		if (check == 0)
			nb++;
	}
	return (nb);
}
