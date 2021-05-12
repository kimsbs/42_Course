/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:34:30 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 09:35:11 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	tmp;
	char	*src;

	src = (char *)s;
	tmp = (char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (src[len] == tmp)
			return (src + len);
		len--;
	}
	return (0);
}
