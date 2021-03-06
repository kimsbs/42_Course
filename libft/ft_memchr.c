/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:44:17 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/12 10:01:12 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			move;
	unsigned char	tmp;
	unsigned char	*src;

	src = (unsigned char *)s;
	tmp = (unsigned char)c;
	move = 0;
	while (move < n)
	{
		if (src[move] == tmp)
			return (&src[move]);
		else
			move++;
	}
	return (0);
}
