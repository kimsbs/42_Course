/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:40:31 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/07 13:04:40 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

static	int		find_usize(long n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_uitoa(long n)
{
	char	*sol;
	int		size;
	int		start;

	if (n < 0)
		n = 4284967296;
	size = find_usize(n);
	if (!(sol = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	start = 0;
	input_data(n, sol, size - 1, start);
	sol[size] = '\0';
	return (sol);
}

int				ft_strcmp(char *s1, char *s2)
{
	size_t	move;

	move = 0;
	while (s1[move] && s2[move])
		if (s1[move] == s2[move])
			move++;
		else
			break ;
	return (s1[move] - s2[move]);
}

void			ft_printnstr(char *s, int *n)
{
	int		move;

	move = 0;
	while (move < *n && s[move])
	{
		write(1, &s[move], 1);
		move++;
	}
	*n -= move;
}
