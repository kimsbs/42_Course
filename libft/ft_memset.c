/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:41:44 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/12 10:02:34 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			move;
	unsigned char	tmp;
	unsigned char	*src;

	src = (unsigned char *)b;
	tmp = (unsigned char)c;
	move = 0;
	while (move < len)
	{
		src[move] = tmp;
		move++;
	}
	return (b);
}
