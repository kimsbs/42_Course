/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:41:18 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 16:41:14 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_in(char c, int flag)
{
	if (c == 'c' || c == 'p' || c == 's' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
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

char			*hexhex(unsigned long long dummy, int move, int up, char *str)
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

char			*go_to_hex(unsigned long long dummy, int cnt, int up)
{
	char				*str;
	unsigned long long	tmp;

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
