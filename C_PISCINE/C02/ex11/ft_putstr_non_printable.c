/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:44:05 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 19:54:40 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	char_to_hex(unsigned char str)
{
	unsigned char tmp;

	if (str <= 9)
		tmp = str + '0';
	else
		tmp = str + 'a' - 10;
	ft_putchar(tmp);
}

void	checker(char str)
{
	char tmp;

	tmp = '\\';
	if (str >= ' ' && str <= '~')
	{
		write(1, &str, 1);
	}
	else
	{
		write(1, &tmp, 1);
		char_to_hex((unsigned char)str / 16);
		char_to_hex((unsigned char)str % 16);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		checker(*str);
		str++;
	}
}
