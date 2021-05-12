/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:23:28 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 13:31:50 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		len;
	unsigned int		i;
	char				*tmp;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp[len] = '\0';
	i = 0;
	while (i < len)
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	return (tmp);
}
