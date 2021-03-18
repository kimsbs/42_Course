/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:56:42 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/08 14:15:30 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt(int nb)
{
	int move;
	int tmp;

	tmp = 1;
	move = 1;
	while (tmp < nb)
	{
		move++;
		tmp = move * move;
		if (move == 46340)
			break ;
	}
	if (tmp == nb)
		return (move);
	else
		return (0);
}
