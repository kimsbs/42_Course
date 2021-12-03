/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:47:50 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/12 10:00:57 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	tmp;
	unsigned char	*dest;
	unsigned char	*source;
	size_t			move;

	move = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	tmp = (unsigned char)c;
	if (!dest && !source)
		return (0);
	while (move < n)
	{
		dest[move] = source[move];
		if (source[move] == tmp)
			return (&dest[move + 1]);
		move++;
	}
	return (0);
}
