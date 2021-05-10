/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:18:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 17:55:35 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size_x(char const *s, char c)
{
	int		len;
	int		x_cnt;

	x_cnt = 0;
	len = 0;
	while (*s)
	{
		if (*s == c && len > 0)
		{
			x_cnt++;
			len = 0;
		}
		else if (*s != c)
			len++;
		s++;
	}
	if (len > 0)
		x_cnt++;
	return (x_cnt);
}

static	void	do_copy(char **s1, char *s2, int len, int x)
{
	int		i;

	i = 0;
	while (i < len && s2[i])
	{
		s1[x][i] = s2[i];
		i++;
	}
	s1[x][i] = '\0';
}

static	void	make_split(char **sol, char *s, char c, int x)
{
	int		len;
	int		i;
	int		y;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c && len > 0)
		{
			sol[x] = (char *)malloc(sizeof(char) * (len + 1));
			do_copy(sol, &s[i - len], len, x);
			len = 0;
			y = 0;
			x++;
		}
		else if (s[i] != c)
			len++;
		i++;
	}
	if (len > 0)
	{
		sol[x] = (char *)malloc(sizeof(char) * (len + 1));
		do_copy(sol, &s[i - len], len, x);
	}
}

char			**ft_split(char const *s, char c)
{
	int		x;
	char	**sol;
	char	*tmp;

	if (!s)
		return (0);
	tmp = (char *)s;
	x = size_x(s, c);
	if (!(sol = (char **)malloc(sizeof(char *) * (x + 1))))
		return (0);
	make_split(sol, tmp, c, 0);
	sol[x] = NULL;
	return (sol);
}
