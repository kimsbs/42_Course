/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:15:53 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/06 19:42:28 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stringcpy(unsigned char *src, unsigned char *tmp, size_t len)
{
	size_t move;

	move = 0;
	while (move < len)
	{
		tmp[move] = src[move];
		move++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			move;
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	*tmp;

	tmp = (unsigned char *)malloc(sizeof(unsigned char) * len);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	stringcpy(source, tmp, len);
	move = 0;
	while (move < len)
	{
		dest[move] = tmp[move];
		move++;
	}
	return (dst);
}
