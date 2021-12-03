/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 01:53:10 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/11 01:53:47 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *arr;
	int move;

	move = 0;
	if (max <= min)
		return (0);
	if (!(arr = (int *)malloc(sizeof(int) * (max - min))))
		return (0);
	while (move + min < max)
	{
		arr[move] = min + move;
		move++;
	}
	return (arr);
}
