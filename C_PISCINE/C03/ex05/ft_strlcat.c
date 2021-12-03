/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:37:36 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 16:37:48 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int rt;
	unsigned int i;
	unsigned int src_size;

	rt = 0;
	i = 0;
	src_size = 0;
	while (dest[i])
		i++;
	while (src[src_size])
		src_size++;
	if (size == 0)
		return (src_size);
	else if (size < i)
		return (size + src_size);
	else
	{
		while (src[rt] && rt + i + 1 < size)
		{
			dest[i + rt] = src[rt];
			rt++;
		}
		dest[i + rt] = '\0';
		return (i + src_size);
	}
}
