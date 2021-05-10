/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:56:37 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 17:56:56 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_in(char const c, char const *set)
{
	while (*set)
		if (*set == c)
			return (1);
		else
			set++;
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		move;
	int		eof;
	int		i;
	char	*tmp;

	if (!s1 || !set)
		return (0);
	eof = ft_strlen(s1);
	move = 0;
	while (is_in(s1[move], set))
		move++;
	while (is_in(s1[eof - 1], set) && move != eof)
		eof--;
	if (!(tmp = (char *)malloc(sizeof(char) * (eof - move + 1))))
		return (0);
	i = -1;
	while (++i < eof - move)
		tmp[i] = s1[move + i];
	tmp[i] = '\0';
	return (tmp);
}
