/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyolee <yong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:31:49 by jaeyolee          #+#    #+#             */
/*   Updated: 2021/03/14 22:25:56 by hyempark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_is_space(char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int		ft_is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		trim_check(char *str)
{
	while (*str)
	{
		if (*str == '\n' || *str == ':')
			break ;
		if (!ft_is_space(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

char	*trim_null_free(char *nb)
{
	free(nb);
	return (NULL);
}

char	*trim_unsigned_int(char *str)
{
	char	*nb;
	int		i;

	while (ft_is_space(*str))
		++str;
	if (*str == '+')
		++str;
	if (!ft_is_digit(*str))
		return (NULL);
	nb = (char *)malloc(sizeof(char) * 40);
	i = 0;
	while (*str && ft_is_digit(*str))
	{
		if (i >= 39)
			return (trim_null_free(nb));
		nb[i++] = *str++;
	}
	nb[i] = '\0';
	if (!trim_check(str))
		return (trim_null_free(nb));
	return (nb);
}
