/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:30:28 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/09 12:14:06 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_something2(char c, va_list op, int flag, t_list *sub)
{
	char	*print;
	int		len;

	len = 0;
	if (c == 'x' || c == 'X' || c == 'p')
	{
		if (c == 'p')
		{
			print = go_to_hex(va_arg(op, unsigned long long), 0, 0);
			return (print_function_ppp(print, flag, sub));
		}
		else if (c == 'X')
			print = go_to_hex(va_arg(op, unsigned int), 0, 1);
		else
			print = go_to_hex(va_arg(op, unsigned int), 0, 0);
		return (print_function_integer(print, flag, sub));
	}
	else if (c == '%')
		len = print_function_per('%', flag, sub);
	else if (c == 'u')
	{
		print = ft_uitoa(va_arg(op, unsigned int));
		len = print_function_integer(print, flag, sub);
	}
	return (len);
}

int		write_something1(va_list op, int flag, t_list *sub)
{
	char	*print;

	print = va_arg(op, char *);
	if (!print)
		print = ft_strdup1("(null)");
	else
		print = ft_strdup1(print);
	return (print_function_string(print, flag, sub));
}

int		write_something(char c, va_list op, int flag, t_list *sub)
{
	char	*print;
	char	tmp;
	int		len;

	if (c == 'd' || c == 'i')
	{
		print = ft_itoa(va_arg(op, int));
		return (print_function_integer(print, flag, sub));
	}
	else if (c == 's')
		return (write_something1(op, flag, sub));
	else if (c == 'c')
	{
		tmp = va_arg(op, int);
		len = 1;
		return (print_function_char(tmp, flag, sub));
	}
	else
		len = write_something2(c, op, flag, sub);
	return (len);
}
