/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:27:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/06 18:02:52 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			move;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	move = 0;
	if (!dest && !source)
    return (0);
	while (move < n)
	{
		dest[move] = source[move];
		move++;
	}
  return (dst);
}
