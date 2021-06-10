/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:30:28 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 16:46:46 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_something3(char c, va_list op, int flag, t_list *sub)
{
	char *print;

	if (c == 'p')
	{
		if ((print = go_to_hex(va_arg(op, unsigned long long), 0, 0)))
			return (print_function_ppp(print, flag, sub));
	}
	else if (c == 'X')
		print = go_to_hex(va_arg(op, unsigned int), 0, 1);
	else
		print = go_to_hex(va_arg(op, unsigned int), 0, 0);
	if (print)
		return (print_function_integer(print, flag, sub));
	free(sub);
	return (-1);
}

int		write_something2(char c, va_list op, int flag, t_list *sub)
{
	char	*print;

	if (c == 'x' || c == 'X' || c == 'p')
		return (write_something3(c, op, flag, sub));
	else if (c == '%')
		return (print_function_per('%', flag, sub));
	else if (c == 'u')
	{
		if ((print = ft_uitoa(va_arg(op, unsigned int))))
			return (print_function_integer(print, flag, sub));
		free(sub);
		return (-1);
	}
	return (-1);
}

int		write_something1(va_list op, int flag, t_list *sub)
{
	char	*print;

	print = va_arg(op, char *);
	if (!print)
		print = ft_strdup1("(null)");
	else
		print = ft_strdup1(print);
	if (print)
		return (print_function_string(print, flag, sub));
	free(sub);
	return (-1);
}

int		write_something(char c, va_list op, int flag, t_list *sub)
{
	char	*print;
	char	tmp;

	if (c == 'd' || c == 'i')
	{
		if ((print = ft_itoa(va_arg(op, int))))
			return (print_function_integer(print, flag, sub));
		free(sub);
		return (-1);
	}
	else if (c == 's')
		return (write_something1(op, flag, sub));
	else if (c == 'c')
	{
		tmp = va_arg(op, int);
		return (print_function_char(tmp, flag, sub));
	}
	else
		return (write_something2(c, op, flag, sub));
}
