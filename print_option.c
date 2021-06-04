/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:30:28 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/04 17:59:48 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_print(char *print, t_list *sub, int print_width, char set)
{
	if (sub->zero)
		set = '0';
	if (print[0] == '0' && sub->dot && sub->precision <= 0)
	{
		print_width++;
		print[0] = '\0';
	}
	if (sub->minus)
	{
		set = ' ';
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		ft_putstr(print);
	}
	while (print_width-- > 0)
		write(1, &set, 1);
	if (!sub->minus)
	{
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		ft_putstr(print);
	}
}

int		print_function(char *print, int flag, t_list *sub)
{
	int len;
	int	print_width;

	len = ft_strlen(print);
	print_width = sub->width - is_max(sub->precision, len);
	sub->precision -= len;
	if (print_width > 0)
		len += print_width;
	if (sub->precision > 0)
		len += sub->precision;
	if (flag)
		print_print(print, sub, print_width, ' ');
	free(print);
	free(sub);
	return (len);
}

int		write_something2(char c, va_list op, int flag, t_list *sub)
{
	char	*print;
	int		len;

	len = 0;
	if (c == 'x' || c == 'X' || c == 'p')
	{
		if (c == 'X')
			print = go_to_hex(va_arg(op, long), 0, 0, 1);
		else
			print = go_to_hex(va_arg(op, long), 0, 0, 0);
		if (c == 'p')
			print = ft_strjoin("0x", print);
		return (print_function(print, flag, sub));
	}
	else if (c == '%')
	{
		print = make_str('%');
		len = print_function(print, flag, sub);
	}
	else if (c == 'u')
	{
		print = ft_uitoa(va_arg(op, long));
		len = print_function(print, flag, sub);
	}
	return (len);
}

int		write_something1(va_list op, int flag, t_list *sub)
{
	char	*print;

	print = va_arg(op, char *);
	if (!print)
		print = ft_strdup("(null)");
	else
		print = ft_strdup(print);
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
