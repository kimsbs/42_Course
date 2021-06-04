/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:42:25 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/04 17:42:48 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, sizeof(char));
		s++;
	}
}

char			*ft_strdup(char *s1)
{
	size_t	len;
	int		move;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	move = 0;
	while (s1[move])
	{
		dup[move] = s1[move];
		move++;
	}
	dup[move] = '\0';
	return (dup);
}

void			*ft_memset(void *b, int c, size_t len)
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

int				ft_atoi(const char *str, int *cnt)
{
	long	sol;
	char	*tmp;

	tmp = (char *)str;
	sol = 0;
	if (*tmp == '-')
	{
		(*cnt)++;
		return (-1);
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		sol = (sol * 10) + (*tmp - '0');
		tmp++;
		if (sol > 2147483647)
			return (-1);
		if (sol < -2147483648)
			return (-1);
		(*cnt)++;
	}
	return ((int)sol);
}

int				is_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
