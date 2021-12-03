/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:04:12 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 18:58:08 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;

	i = 0;
	while (dest[i++])
	{
	}
	i--;
	while (nb--)
	{
		if (!(dest[i++] = *src))
			return (dest);
		src++;
	}
	dest[i] = '\0';
	return (dest);
}
