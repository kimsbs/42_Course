/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:37:56 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/12 10:05:58 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	move;

	move = 0;
	while (move < n && s1[move] && s2[move])
		if (s1[move] == s2[move])
			move++;
		else
			break ;
	if (n == 0)
		return (0);
	else if (move < n)
		return ((unsigned char)s1[move] - (unsigned char)s2[move]);
	else
		return (0);
}
