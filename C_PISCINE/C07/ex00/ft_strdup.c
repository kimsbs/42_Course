/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:37:35 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/25 21:42:45 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*new;

	len = 0;
	while (src[len])
		len++;
	new = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (src[len])
	{
		new[len] = src[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}
