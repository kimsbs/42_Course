/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:41:18 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/07 18:12:27 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_in(char *s, char c, int flag)
{
	int move;

	move = 0;
	while (s[move])
	{
		if (c == s[move])
			return (move);
		move++;
	}
	if (c == ' ' && flag)
		write(1, &c, 1);
	return (-1);
}

void			upper_string(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s += 'A' - 'a';
		s++;
	}
}

char			*hexhex(long dummy, int move, int up, char *str)
{
	char	*hex;

	hex = "0123456789abcdef";
	while (--move >= 0)
	{
		str[move] = hex[dummy % 16];
		dummy /= 16;
	}
	if (up)
		upper_string(str);
	return (str);
}

char			*go_to_hex(long dummy, int cnt, long tmp, int up)
{
	char	*str;

	cnt = 0;
	tmp = dummy;
	while (tmp)
	{
		tmp /= 16;
		cnt++;
	}
	if (dummy == 0)
		cnt++;
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (0);
	str[cnt] = '\0';
	return (hexhex(dummy, cnt, up, str));
}

char			*ft_strjoin1(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup1(s2));
	else if (!s2)
		return (ft_strdup1(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy(&join[s1_len], s2, s2_len + 1);
	free(s2);
	return (join);
}
