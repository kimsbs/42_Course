/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:17:51 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 19:59:50 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int cnt;

	i = 0;
	cnt = 0;
	if (dest == 0 || src == 0)
		return (0);
	while (src[cnt])
		cnt++;
	if (size != 0)
	{
		while (src[i] != '\0' && i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (cnt);
}
