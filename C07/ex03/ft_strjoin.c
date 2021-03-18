/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:24:36 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/08 17:34:22 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		counting(char *strs, char *sep)
{
	int cnt;

	cnt = 0;
	while (*strs++)
		cnt++;
	while (*sep++)
		cnt++;
	cnt++;
	return (cnt);
}

char	*init_tmp(char **strs, char *sep, int size)
{
	int		cnt;
	int		move;
	char	*tmp;

	cnt = 0;
	if (!size)
		tmp = (char *)malloc(sizeof(char) * 1);
	else
	{
		move = -1;
		while (++move < size)
			cnt += counting(strs[move], sep);
		tmp = (char *)malloc(sizeof(char) * (cnt + 1));
	}
	return (tmp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tmp;
	int		move;
	int		move_sep;
	int		move_t;

	tmp = init_tmp(strs, sep, size);
	if (size)
	{
		move = -1;
		move_t = 0;
		while (++move < size)
		{
			move_sep = 0;
			while (*strs[move])
				tmp[move_t++] = *strs[move]++;
			if (move != size - 1)
				while (sep[move_sep])
					tmp[move_t++] = sep[move_sep++];
		}
		tmp[move_t] = '\0';
	}
	else
		tmp[0] = 0;
	return (tmp);
}
