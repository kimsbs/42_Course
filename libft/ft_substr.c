/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:54:41 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 17:57:54 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int		alloc_size(unsigned int length, unsigned int start,
		size_t len)
{
	unsigned int tmp;

	tmp = (unsigned int)len;
	if (length - start < tmp)
		length = length - start;
	else
		length = tmp;
	return (length);
}

char						*ft_substr(char const *s, unsigned int start,
		size_t len)
{
	char			*tmp;
	size_t			move;
	unsigned int	length;
	unsigned int	alloc_len;

	if (!s)
		return (0);
	length = ft_strlen(s);
	alloc_len = alloc_size(length, start, len);
	if (length <= start)
	{
		tmp = (char *)malloc(sizeof(char) * 1);
		tmp[0] = '\0';
		return (tmp);
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (alloc_len + 1))))
		return (0);
	move = -1;
	while (++move < len && s[start + move])
		tmp[move] = s[start + move];
	tmp[move] = '\0';
	return (tmp);
}
