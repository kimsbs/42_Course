/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:14:05 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/08 11:21:07 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check(char *str, char *to_find, int pivot)
{
	int i;

	i = 0;
	while (to_find[i])
	{
		if (str[pivot] == to_find[i])
		{
			pivot++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int pivot;
	int sol;

	sol = 0;
	pivot = -1;
	if (!*to_find)
		return (str);
	while (str[++pivot])
	{
		if (str[pivot] == to_find[0])
		{
			sol = check(str, to_find, pivot);
			if (sol == 1)
			{
				return (str + pivot);
			}
		}
	}
	return (0);
}
