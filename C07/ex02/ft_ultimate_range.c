/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:16:14 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/11 05:13:32 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int move;
	int *tmp;

	if (max <= min)
		range = NULL;
	else
	{
		if (!(tmp = malloc(sizeof(int) * (max - min))))
			return (-1);
		move = 0;
		while (move + min < max)
		{
			tmp[move] = min + move;
			move++;
		}
		*range = tmp;
		return (max - min);
	}
	return (0);
}
