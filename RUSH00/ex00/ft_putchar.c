/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:25:12 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/20 15:32:10 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int x, char first, char middle, char last)
{
	char i;
	char tmp;

	i = '0';
	tmp = '\n';
	while (i < x + 48)
	{
		if (i == 48)
		{
			write(1, &first, 1);
		}
		else if (i == x - 1 + 48)
		{
			write(1, &last, 1);
		}
		else
		{
			write(1, &middle, 1);
		}
		i++;
	}
	write(1, &tmp, 1);
}
