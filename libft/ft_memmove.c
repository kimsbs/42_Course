/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:15:53 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/12 10:02:10 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			move;
	unsigned char	*dest;
	unsigned char	*source;

	if (dst == src || len == 0)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	move = 0;
	while (move < len)
	{
		if (dst < src)
			dest[move] = source[move];
		else
			dest[len - move - 1] = source[len - move - 1];
		move++;
	}
	return (dst);
}
