/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:14:16 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/17 15:40:39 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tmp;

	tmp = (int *)malloc(sizeof(int) * length);
	i = -1;
	while (++i < length)
		tmp[i] = f(tab[i]);
	return (tmp);
}
