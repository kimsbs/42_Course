/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:39:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/18 16:35:56 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_in(char *s, char c)
{
	int move;

	move = 0;
	while(s[move])
	{
		if(c == s[move])
			return (move);
		move++;
	}
	return (-1);
}

int		print_function(char *print, int flag, t_list *sub)
{
	int len;
	int	print_width;
	char set;

	set = ' ';
	len = ft_strlen(print);
	print_width = sub->width - is_max(sub->precision, len);
	sub->precision -= len;
	if(flag)
	{
		if(sub->zero)
			set = '0';
		if(sub->minus)
		{
			while((sub->precision)-- > 0)
				write(1, "0", 1);
			ft_putstr(print);
		}
		while(print_width-- > 0)
			write(1, &set, 1);
		if(!sub->minus)
		{
			while((sub->precision)-- > 0)
				write(1, "0", 1);
			ft_putstr(print);
		}
	}
	len = is_max(len, sub->width);
	free(print);
	free(sub);
	return (len);
}

int		write_something(char c, va_list op, int flag, t_list *sub)
{
	char	*print;
	int		len;

	len = 0;
	if(c == 'd' || c == 'i')
	{
		print = ft_itoa(va_arg(op, int));
		len = print_function(print, flag, sub);
	}
	else if(c == 's')
	{
		print = va_arg(op, char *);
		if(!print)
			print = ft_strdup("(null)");
		else
			print = ft_strdup(print);
		len = print_function(print, flag, sub);
	}	
	else if(c == 'c')
	{
		print = make_str(va_arg(op, int));
		len = print_function(print, flag, sub);
	}
	return (len);
}

int		is_flag(va_list op, char *string, int last, int flag)
{
	int 	move;
	int		cnt;
	t_list	*sub;

	sub = (t_list *)malloc(sizeof(t_list));
	ft_memset(sub, 0, sizeof(t_list));
	move = 1;
	if(string[move] == '-')
	{
		sub->minus = 1;
		move++;
	}
	while(move < last)
	{
		while(string[move] == '0')
		{
			sub->zero = 1;
			move++;
		}
		if(string[move] == '-')
			return (0);
		else if(string[move] == '.')
		{
			cnt = 0;
			if(sub->dot)
				return (0);
			sub->dot = 1;
			sub->zero = 0;
			sub->precision = ft_atoi(&string[move], &cnt);
			move += cnt;
			if(sub->precision < 0)
				return (0);
		}
		else if(string[move] == '*')
		{
			if(string[move - 1] == '.')
				sub->precision = va_arg(op, int);
			else
				if(!sub->width)
					sub->width = va_arg(op, int);
				else
					return (0);
		}
		else if(string[move] >= '1' && string[move] <= '9')
		{
			if(!sub->width)
			{
				cnt = 0;
				sub->width = ft_atoi(&string[move], &cnt);
				move += cnt;
				if(sub->width < 0)
					return (0);
			}
			else
				return (0);
		}
		move++;
	}
	return(write_something(string[last], op, flag, sub));
}

int		available(va_list op, char *string, char *set, int flag, int string_length)
{
	int	move;
	int	tmp;
	int	dummy;
	int return_value;

	move = -1;
	return_value = 0;
	while(++move < string_length)
		if(string[move] != '%')
		{
			if(flag)
				write(1, &string[move], sizeof(char));
			return_value++;
		}
		else
		{
			tmp = 1;
			while(move + tmp < string_length && (is_in(set, string[move + tmp]) == -1))
				tmp++;
			if((dummy = is_flag(op, &string[move], tmp, flag)))
				return_value += dummy;
			else
				return (0);
			move += tmp;
		}
	return (return_value);
}

int 	ft_printf(const char *string, ...)
{
	va_list	op;
	int		return_value;
	char	*set;
	int		str_len;

	str_len = ft_strlen(string);
	set = ft_strdup("cspdiuxX%");
	va_start(op, string);
	return_value = available(op, (char *)string, set, 0, str_len);
	va_end(op);
	va_start(op, string);
	if(return_value)
		available(op, (char *)string, set, 1, str_len);
	va_end(op);
	free(set);
	return (return_value);
}
