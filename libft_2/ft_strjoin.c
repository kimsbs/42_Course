/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:35:49 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 17:04:09 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	move;
	char	*join;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	move = 0;
	while (move < s1_len)
	{
		join[move] = s1[move];
		move++;
	}
	while (move - s1_len < s2_len)
	{
		join[move] = s2[move - s1_len];
		move++;
	}
	join[move] = '\0';
	return (join);
}
