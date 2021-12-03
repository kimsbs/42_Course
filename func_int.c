/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:15:53 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/07 18:29:56 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_integer2(char *print, t_list *sub, int print_width, char set)
{
	if (print[0] == '-' && set == '0')
		write(1, &*(print++), 1);
	while (print_width-- > 0)
		write(1, &set, 1);
	if (!sub->minus)
	{
		if (print[0] == '-')
			write(1, &*(print++), 1);
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		ft_putstr(print);
	}
}

void	print_integer(char *print, t_list *sub, int print_width)
{
	char set;

	set = ' ';
	if (sub->zero == 1)
		set = '0';
	if (!ft_strcmp(print, "0") && sub->dot && sub->precision < 0)
	{
		print_width++;
		print[0] = '\0';
	}
	if (sub->minus)
	{
		set = ' ';
		if (print[0] == '-')
			write(1, &*(print++), 1);
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		ft_putstr(print);
	}
	print_integer2(print, sub, print_width, set);
}

int		print_function_integer(char *print, int flag, t_list *sub)
{
	int len;
	int	print_width;

	len = ft_strlen(print);
	print_width = sub->width - is_max(sub->precision, len);
	sub->precision -= len;
	if (sub->precision >= 0)
	{
		if (print[0] == '-' && sub->dot)
		{
			sub->precision++;
			print_width--;
		}
		len += sub->precision;
	}
	if (print_width > 0)
		len += print_width;
	if (!ft_strcmp(print, "0") && sub->dot && sub->precision < 0
			&& print_width < 0)
		len--;
	if (flag)
		print_integer(print, sub, print_width);
	free(print);
	free(sub);
	return (len);
}
